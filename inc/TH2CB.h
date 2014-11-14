#ifndef TH2CB_H
#define TH2CB_H

#include <set>

#include "matrixstack.h"
#include "TH2DrawTool.h"
#include "TH2Poly.h"
using namespace a2::display;
//namespace a2 {
//namespace display {

class TH2CB: public TH2Poly {
protected:
    typedef matrixstack::Vector vec;

    virtual void Build();
    void MakeLevel(a2::display::TH2DrawTool& c, const vec& a, const vec& b, const UInt_t n );

    static const a2::display::TH2DrawTool::point_list shape;
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

//}
//}

#endif
