#ifndef XHIST_H
#define XHIST_H

#include "matrixstack.h"
#include "TH2Poly.h"
#include "Rtypes.h"

#include <set>

#define TAPS_CONFIG "BaF2-PbWO4.dat"

class TH2DrawTool: public matrixstack {
private:
    TH2Poly* hist;

    std::vector<double> x;
    std::vector<double> y;

public:
    TH2DrawTool( TH2Poly* target );
    virtual ~TH2DrawTool() {}

    void Draw( const matrixstack::Vector& vector );

    typedef std::vector<matrixstack::Vector> point_list;

    void Draw( const point_list& points );

    Int_t FinishShape();
    void ResetShape();
};

class TH2TAPS: public TH2Poly {
protected:
    virtual void Build();
public:
    TH2TAPS() { Build(); }
    virtual ~TH2TAPS() {}
};


class TH2CB: public TH2Poly {
protected:
    typedef matrixstack::Vector vec;

    virtual void Build();
    void MakeLevel(TH2DrawTool& c, const vec& a, const vec& b, const UInt_t n );

    static const TH2DrawTool::point_list shape;
    static const std::set<Int_t> bins_in_holes;

public:
    TH2CB( const std::string& name="", const std::string& title="" );
    virtual ~TH2CB() {}
    static Int_t GetElement( const UChar_t a, const UChar_t b, const UChar_t c);
    static bool IsInHole(const Int_t bin);

    void SetHoles( const double v=-1 );
    void FillNumber();
    void FillElementNumber();
};

#endif
