#ifndef TH2TAPS_H
#define TH2TAPS_H

#include "TH2DrawTool.h"
#include "TH2Poly.h"
#include "a2display.h"

#define TAPS_CONFIG "BaF2-PbWO4.dat"

class TH2TAPS: public TH2Crystals {
    ClassDef(TH2TAPS,1);

protected:
    virtual void Build();
public:
    TH2TAPS( const std::string& name, const std::string& title);
    virtual ~TH2TAPS() {}
};

#endif
