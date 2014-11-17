#ifndef A2DISPLAY_H
#define A2DISPLAY_H

#include "TH2Poly.h"
#include <string>
#include "matrixstack.h"

class TH2Crystals: public TH2Poly {
ClassDef(TH2Crystals,1);

protected:
    typedef matrixstack::Vector vec;

public:

    TH2Crystals(const std::string &name="", const std::string &title="");
    virtual ~TH2Crystals() {}

    virtual Double_t GetElement( const UInt_t element ) const;
    virtual void SetElement( const UInt_t element, Double_t value );

    /**
     * @brief Fill the number of the TH2Poly bin. Useful for debugging only, I guess.
     */
    virtual void FillBinNumbers();

    virtual void FillElementNumbers();

    virtual void FillElements( const std::vector<Double_t>& pattern );

    virtual UInt_t GetNumberOfElements();

    virtual void SetAllBins( const Double_t value );

};

#endif
