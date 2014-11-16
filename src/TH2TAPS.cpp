#include "TH2TAPS.h"
#include "TMath.h"

#include <fstream>
#include <iostream>

using namespace std;

TH2TAPS::TH2TAPS(const string &name, const string &title): TH2Crystals(name,title)
{
    Build();
}

TH2DrawTool::point_list TH2TAPS::MakeBaF2Shape()
{
    matrixstack s;
    TH2DrawTool::point_list shape(7);

    const vec va(a,0);

    for(int i=0;i<6;++i) {
        shape.at(i) = s.Transform(va);
        s.Rotate(60.0*TMath::DegToRad());
    }
    shape.at(6) = shape.at(0);

    return shape;
}

TH2DrawTool::point_list TH2TAPS::MakePbWO4Shape()
{
    TH2DrawTool::point_list shape(5);

    shape.at(0) = vec(+1.299,0-b/2);
    shape.at(1) = vec(+1.299,     b-b/2);
    shape.at(2) = vec(-a/2.0+1.299,  b-b/2);
    shape.at(3) = vec(-a+1.299,    -b/2);
    shape.at(4) = shape.at(0);

    // calculate center of PbWO4 shape
    vec pbwo4_center;
    for( int i=0;i<4; ++i) {
        pbwo4_center += shape.at(i);
    }
    pbwo4_center /= 4;

    matrixstack s;
    s.Translate(pbwo4_center);

    for( int i=0;i<shape.size(); ++i) {
        shape.at(i) = s.Transform(shape.at(i));
    }

    return shape;
}

void TH2TAPS::Build()
{
    TH2DrawTool c(this);

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

        const TH2DrawTool::point_list* shape = NULL;

        if( type == "B") {
            shape = &baf2_shape;
        }
        else if( type[0] == 'P') {
            switch (type[1]) {
            case '0':
                shape=&pbwo4_shape;
                c.Scale(-1,1);
                break;
            case '1':
                shape=&pbwo4_shape;
                break;
            case '2':
                shape=&pbwo4_shape;
                c.Scale(-1,-1);
                break;
            case '3':
                shape=&pbwo4_shape;
                c.Scale(1,-1);
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

const TH2DrawTool::point_list TH2TAPS::baf2_shape = TH2TAPS::MakeBaF2Shape();
const TH2DrawTool::point_list TH2TAPS::pbwo4_shape = TH2TAPS::MakePbWO4Shape();
// Build a BaF2 crystal
const Double_t TH2TAPS::a = 3.464; // edgle length of BaF2 in cm
const Double_t TH2TAPS::b = 3.0;   // half distance of parallels of BaF2 in cm
