#include "TH2TAPS.h"
#include "TMath.h"

#include <fstream>
#include <iostream>

using namespace a2::display;
//namespace a2 {
//namespace display {

using namespace std;

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

//}
//}
