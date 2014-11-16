#ifndef TH2TAPS_H
#define TH2TAPS_H

#include "TH2DrawTool.h"
#include "TH2Poly.h"
#include "a2display.h"

#define TAPS_CONFIG "BaF2-PbWO4.dat"

class TH2TAPS: public TH2Crystals {
    ClassDef(TH2TAPS,1);

protected:

    static TH2DrawTool::point_list MakeBaF2Shape();
    static TH2DrawTool::point_list MakePbWO4Shape();

    static const Double_t a;
    static const Double_t b;

    static const TH2DrawTool::point_list baf2_shape;
    static const TH2DrawTool::point_list pbwo4_shape;
    virtual void Build();
public:
    TH2TAPS( const std::string& name, const std::string& title);
    virtual ~TH2TAPS() {}
};

#endif
