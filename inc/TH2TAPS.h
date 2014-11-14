#ifndef TH2TAPS_H
#define TH2TAPS_H

#include "TH2DrawTool.h"
#include "TH2Poly.h"

#define TAPS_CONFIG "BaF2-PbWO4.dat"

class TH2TAPS: public TH2Poly {
    ClassDef(TH2TAPS,1);

protected:
    virtual void Build();
public:
    TH2TAPS() { Build(); }
    virtual ~TH2TAPS() {}
};

#endif
