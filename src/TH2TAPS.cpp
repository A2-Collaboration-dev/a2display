#include "TH2TAPS.h"
#include "TMath.h"
#include "TH2Poly.h"

#include "taps_positions.h"

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

    // Crystal positions in config file are viewed from behind TAPS. Turn this around to get downstream view.
    c.Scale(-1,1);

    for( UInt_t i=0; i<NUM_TAPS_CRYSTALS; ++i ) {

        const vec pos (taps_positions[i].x,
                       taps_positions[i].y);
        const UChar_t& type = taps_positions[i].type;

        c.PushMatrix();

        c.Translate(pos);

        switch (type) {
            case 0:
                c.Draw(baf2_shape);
                break;
            case 1:
                c.Scale(-1,1);
                c.Draw(pbwo4_shape);
                break;
            case 2:
                c.Draw(pbwo4_shape);
                break;
            case 3:
                c.Scale(-1,-1);
                c.Draw(pbwo4_shape);
                break;
            case 4:
                c.Scale(1,-1);
                c.Draw(pbwo4_shape);
                break;
        }
        c.FinishShape();
        c.PopMatrix();
    }

    SetStats(kFALSE);
    SetXTitle("x [cm]");
    SetYTitle("y [cm]");

}

const TH2DrawTool::point_list TH2TAPS::baf2_shape = TH2TAPS::MakeBaF2Shape();
const TH2DrawTool::point_list TH2TAPS::pbwo4_shape = TH2TAPS::MakePbWO4Shape();
// Build a BaF2 crystal
const Double_t TH2TAPS::a = 3.464; // edgle length of BaF2 in cm
const Double_t TH2TAPS::b = 3.0;   // half distance of parallels of BaF2 in cm
