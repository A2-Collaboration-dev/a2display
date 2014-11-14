#ifndef TH2CB_H
#define TH2CB_H

#include <set>
#include <vector>

#include "matrixstack.h"
#include "TH2DrawTool.h"
#include "TH2Poly.h"

class TH2CB: public TH2Poly {
    ClassDef(TH2CB,1);

protected:
    typedef matrixstack::Vector vec;

    virtual void Build();
    void MakeLevel(a2::display::TH2DrawTool& c, const UInt_t n, std::set<Int_t>::const_iterator& nexthole, UInt_t& vbins);

    static const a2::display::TH2DrawTool::point_list shape;    // shape of a crystal
    static const std::set<Int_t> bins_in_holes;     // vbin numbers in holes
    static const std::vector<Int_t> binmap;         // maps vbin to bin
    static const std::vector<Int_t> Make_binmap();

public:
    TH2CB( const std::string& name="", const std::string& title="" );
    virtual ~TH2CB() {}

    static Int_t GetBinOfElement( const UChar_t a, const UChar_t b, const UChar_t c);
    static Int_t GetVBinOfElement( const UChar_t a, const UChar_t b, const UChar_t c);
    static Int_t GetBinOfVBin( const Int_t vbin );

    static bool IsInHole( const UChar_t a, const UChar_t b, const UChar_t c);
    static bool IsInHole( const Int_t vbin );

    /**
     * @brief Fill the number of the TH2Poly bin. Useful for debugging only, I guess.
     */
    void FillBinNumber();

    /**
     * @brief Fill the crystal number.
     *
     * Crystal numers count in the same way as the element numbers (ex.: 1/1/1), stating with 1 (conflit?)
     */
    void FillCrystalNumber();

    /**
     * @brief Fill the element numbers in. ex: 1/1/1 -> 111 and 14/2/8 -> 1428.
     */
    void FillElementNumber();

    /**
     * @brief Fill a hit pattern (unmapped), only containing existing crystals
     * @param pattern Vector of the lenfth 672 (is checked!)
     * @see FillHitpattern720()
     */
    void FillHitpattern672( const std::vector<Double_t>& pattern );

    /**
     * @brief Fil a hit pattern (unmapped), containing crystals in holes
     * @param pattern Vector of the lenfth 720 (is checked!)
     * @see FillHitpattern672()
     */
    void FillHitpattern720( const std::vector<Double_t>& pattern );

    /**
     * @brief Get value of a crystal (unmapped), only counting exising crystals (no holes)
     * @param i Crystal number [0..671]
     * @return Content of the crystal
     */
    Double_t GetCrystal672(const UInt_t i) const;

    /**
     * @brief Get value of a crystal (unmapped), counting also crystals in holes
     * @param i Crystal number, might be in a hole, [0..719]
     * @return Content of the crystal. If the crystal is in a hole, 0.0 ist returend
     */
    Double_t GetCrystal720(const UInt_t i) const;

    /**
     * @brief Set the value of a crystal (unmapped), counting only existing crystals (no holes)
     * @param i Crystal number [0..671]
     * @param value Value to set it it
     * @see SetCrystal720()
     */
    void SetCrystal672(const UInt_t i, Double_t value);

    /**
     * @brief Get value of a crystal (unmapped), counting also crystals in holes
     * @param i Crystal number, might be in a hole, [0..719]
     * @param value Value to set it it
     * @see SetCrystal672()
     */
    void SetCrystal720(const UInt_t i, Double_t value);


};

#endif
