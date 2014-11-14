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
    void MakeLevel(a2::display::TH2DrawTool& c, const UInt_t n, std::set<Int_t>::const_iterator& nexthole, UInt_t& vbins);

    static const a2::display::TH2DrawTool::point_list shape;
    static const std::set<Int_t> bins_in_holes;
    static const std::vector<Int_t> binmap; // maps vbin to bin
    static const std::vector<Int_t> Make_binmap();

public:
    TH2CB( const std::string& name="", const std::string& title="" );
    virtual ~TH2CB() {}

    static Int_t GetBinOfElement( const UChar_t a, const UChar_t b, const UChar_t c);
    static Int_t GetVBinOfElement( const UChar_t a, const UChar_t b, const UChar_t c);
    static Int_t GetBinOfVBin( const Int_t vbin );

    static bool IsInHole( const UChar_t a, const UChar_t b, const UChar_t c);
    static bool IsInHole( const Int_t vbin );

    void FillBinNumber();
    void FillCrystalNumber();
    void FillElementNumber();

    void FillHitpattern672( const std::vector<Double_t>& pattern );
    void FillHitpattern720( const std::vector<Double_t>& pattern );


};

//}
//}

#endif
