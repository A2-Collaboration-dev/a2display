#include "XHist.h"
#include "TMath.h"
#include <iostream>
#include <fstream>
#include <string>
#include "TH2Poly.h"
#include "TH1.h"
#include "TAxis.h"
#include "TPolyLine.h"
#include "TText.h"

using namespace std;
using namespace a2::display;

void TH2TAPS::Build()
{
    TH2DrawTool c(this);
    typedef matrixstack::Vector vec;

    TH2DrawTool::point_list baf_shape(6);
    TH2DrawTool::point_list pbwo4_shape(4);

    // Build a BaF2 crystal
    const double a = 3.464; // edgle length of BaF2 in cm
    const double b = 3.0;   // half distance of parallels of BaF2 in cm


    vec va(a,0);

    c.LoadIdentity();
    c.Translate(va);
    c.Rotate(60.0*TMath::DegToRad());
    c.Translate(va);
    vec ur = c.Transform( vec(0,0) );

    c.LoadIdentity();
    for(int i=0;i<6;++i) {
        baf_shape[i] = c.Transform(va);
        cout << i << ": " << baf_shape[i] << endl;
        c.Rotate(60.0*TMath::DegToRad());
    }
    c.LoadIdentity();

    // create PbWO4 shape
    pbwo4_shape[0] = vec(+1.299,0-b/2);
    pbwo4_shape[1] = vec(+1.299,     b-b/2);
    pbwo4_shape[2] = vec(-a/2.0+1.299,  b-b/2);
    pbwo4_shape[3] = vec(-a+1.299,    -b/2);

    // calculate center of PbWO4 shape
    vec pbwo4_center;
    for( int i=0;i<pbwo4_shape.size(); ++i) {
        pbwo4_center += pbwo4_shape.at(i);
    }
    pbwo4_center /= 4;

/*
    pbwo4_shape[0] = vec( 0.5,   -0.5);
    pbwo4_shape[1] = vec( 1,    1);
    pbwo4_shape[2] = vec(-0.5,    0.5);
    pbwo4_shape[3] = vec(-0.5,   -0.5);
*/

    ifstream conf;
    conf.open(TAPS_CONFIG);
    if(!conf.is_open()) {
        cerr << "Could not open TAPS Crytsal config file \"" << TAPS_CONFIG << "\"" << endl;
        return;
    }

    // Crystal positions in config file are viewed from behind TAPS. Turn this around to get downstream view.
    c.Scale(-1,1);

    while(!conf.eof()) {
        double z;
        UInt_t n;
        vec pos;
        string type;
        conf >> n >> pos.X() >> pos.Y() >> z >> type;

        c.PushMatrix();

        c.Translate(pos);

        TH2DrawTool::point_list* shape = NULL;

        if( type == "B") {
            shape = &baf_shape;
        }
        else if( type[0] == 'P') {
            switch (type[1]) {
            case '0':
                shape=&pbwo4_shape;
                c.Scale(-1,1);
                c.Translate(pbwo4_center);
                break;
            case '1':
                shape=&pbwo4_shape;
                c.Translate(pbwo4_center);
                break;
            case '2':
                shape=&pbwo4_shape;
                c.Scale(-1,-1);
                c.Translate(pbwo4_center);
                break;
            case '3':
                shape=&pbwo4_shape;
                c.Scale(1,-1);
                c.Translate(pbwo4_center);
                break;
            }
        }

        if( shape ) {
            c.Draw(*shape);
            Int_t bin = c.FinishShape();
            SetBinContent(bin,n);
            cout << "Element " << n << " at " << pos << " is " << type << endl;
        }
        c.PopMatrix();
    }

    conf.close();

}


void TH2CB::Build()
{
    TH2DrawTool tool(this);

    const vec& a(shape.at(1));
    const vec& b(shape.at(2));


    vec c;
    c.X() = b.X();
    c.Y() = -b.Y();


    for(int i=0;i<5;++i) {

        for( int j=0; j<2; ++j) {
            MakeLevel(tool,a,b,1);
            tool.Translate(a);
            tool.Scale(-1,-1);
            MakeLevel(tool,a,b,1);
            tool.Translate(b);
            tool.Scale(-1,-1);
        }
        tool.Translate(2.0*b-a);
    }

    SetStats(kFALSE);
    GetXaxis()->SetTickLength(0);
    GetXaxis()->SetLabelSize(0);
    GetYaxis()->SetTickLength(0);
    GetYaxis()->SetLabelSize(0);

    TText* inlabel = new TText(3.24,-0.43,"Beam In");
    inlabel->SetTextSize(0.03);
    inlabel->SetTextAlign(22);  // middle, middle
    GetListOfFunctions()->Add(inlabel);

    TText* outlabel = new TText(0.73,-0.43,"Beam out");
    outlabel->SetTextSize(0.03);
    outlabel->SetTextAlign(22);  // middle, middle
    GetListOfFunctions()->Add(outlabel);

}

void TH2CB::MakeLevel(TH2DrawTool &c, const TH2CB::vec &a, const TH2CB::vec &b, const UInt_t n)
{

    if(n>=4) {
        c.Draw(shape);
        Int_t bin = c.FinishShape();
    } else {
        c.PushMatrix();
        c.Scale(1.0/n,1.0/n);
       for( UInt_t row=0; row<n; ++row){
            const UInt_t triganles = 2*row +1;
            c.PushMatrix();
            c.Translate( (n-row-1.0)* b );
            for( UInt_t t=0; t<triganles; ++t) {
                if(t%2==0) {
                    MakeLevel(c,a,b,n+1);
                    c.Translate(a);}
                else {
                    c.Translate(b);
                    c.Scale(-1,-1);
                    MakeLevel(c,a,b,n+1);
                    c.Translate(b);
                    c.Scale(-1,-1);
                }
            }
            c.PopMatrix();
        }
        c.PopMatrix();
    }

}

TH2CB::TH2CB(const string &name, const string &title)
{
    Build();
    SetNameTitle(name.c_str(),title.c_str());
}

Int_t TH2CB::GetElement(const UChar_t a, const UChar_t b, const UChar_t c)
{
    if (    ( a<1 || a> 20)
         || ( b<1 || b>4 )
         || ( c<1 || c>9 )  ) {
        return -5;  // invalid element specifications mapped to the "sea"
    }

    return (a-1)*4*9 + (b-1)*9 + c;
}

bool TH2CB::IsInHole(const Int_t bin)
{
    return bins_in_holes.find(bin) != bins_in_holes.end();
}

void TH2CB::FillNumber()
{
    for(int i = 1; i<=GetNumberOfBins(); ++i) {
        SetBinContent(i,i);
    }
}

void TH2CB::FillElementNumber()
{
    for( int m=1;m<=20;++m){
        for( int n=1;n<=4;++n) {
            for( int o=1;o<=9;++o) {
                const Int_t number = m*100 + n*10+o;
                const Int_t bin = GetElement(m,n,o);
                SetBinContent(bin,number);
            }
        }
    }
}


void TH2CB::SetHoles(const double v)
{
    std::set<Int_t>::const_iterator bin;
    for( bin= bins_in_holes.begin(); bin != bins_in_holes.end(); ++bin ) {
        SetBinContent(*bin, v);
    }
}

/**
 * @brief Puts points for a triable (edge length =1) into a list
 * @return list of points of the triangle
 */
const TH2DrawTool::point_list MakeTriangle() {
    TH2DrawTool::point_list shape(4);
    shape.at(0) = TH2DrawTool::Vector(0.0, 0.0);
    shape.at(1) = TH2DrawTool::Vector(1.0, 0.0);
    shape.at(2) = TH2DrawTool::Vector(0.5, 0.866025);
    shape.at(3) = shape.at(0);

    return shape;
}

const std::set<Int_t> MakeListOfBinsInholes() {
    std::set<Int_t> list;
    UChar_t elements[2*6*4][3] = {
        {2,1,2},
        {2,1,5},
        {2,1,6},
        {2,1,7},
        {3,2,1},
        {3,2,2},
        {3,2,3},
        {3,2,4},
        {3,3,4},
        {3,3,7},
        {3,3,8},
        {3,3,9},
        {3,1,2},
        {3,1,5},
        {3,1,6},
        {3,1,7},
        {2,2,1},
        {2,2,2},
        {2,2,3},
        {2,2,4},
        {2,3,4},
        {2,3,7},
        {2,3,8},
        {2,3,9},

        {11,1,4},
        {11,1,7},
        {11,1,8},
        {11,1,9},
        {11,3,2},
        {11,3,5},
        {11,3,6},
        {11,3,7},
        {11,4,1},
        {11,4,2},
        {11,4,3},
        {11,4,4},
        {14,1,4},
        {14,1,7},
        {14,1,8},
        {14,1,9},
        {14,3,2},
        {14,3,5},
        {14,3,6},
        {14,3,7},
        {14,4,1},
        {14,4,2},
        {14,4,3},
        {14,4,4}
    };

    for(UChar_t element=0; element < 2*6*4; ++element) {

        list.insert( TH2CB::GetElement(
                         elements[element][0],
                         elements[element][1],
                         elements[element][2]));

    }

    return list;
}

const TH2DrawTool::point_list TH2CB::shape = MakeTriangle();
const std::set<Int_t> TH2CB::bins_in_holes = MakeListOfBinsInholes();
