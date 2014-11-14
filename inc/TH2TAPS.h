#ifndef TH2TAPS_H
#define TH2TAPS_H

#include "TH2DrawTool.h"
#include "TH2Poly.h"
using namespace a2::display;
#define TAPS_CONFIG "BaF2-PbWO4.dat"

//namespace a2 {
//namespace display {

class TH2TAPS: public TH2Poly {
    ClassDef(TH2TAPS,1);

protected:
    virtual void Build();
public:
    TH2TAPS() { Build(); }
    virtual ~TH2TAPS() {}
};

//}
//}

#endif
