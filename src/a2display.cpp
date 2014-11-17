#include "a2display.h"
#include "TDirectory.h"
#include "TIterator.h"
#include <iostream>

TH2Crystals::TH2Crystals( const std::string& name, const std::string& title): TH2Poly()
{
    if(!name.empty())
        SetName(name.c_str());
    if(!title.empty())
        SetTitle(title.c_str());

    SetDirectory(gDirectory);
}

Double_t TH2Crystals::GetElement(const UInt_t element) const
{
    return GetBinContent(element+1);
}

void TH2Crystals::SetElement(const UInt_t element, Double_t value)
{
    SetBinContent( element+1, value);
}

void TH2Crystals::FillBinNumbers() {
    for( Int_t i=0; i < GetNumberOfBins(); ++i ) {
        SetBinContent(i,i);
    }
}

void TH2Crystals::FillElementNumbers()
{
    for( UInt_t i=0; i < GetNumberOfElements(); ++i) {
        SetElement(i,i);
    }
}

void TH2Crystals::FillElements(const std::vector<Double_t> &pattern)
{

    if(pattern.size()==GetNumberOfElements()) {

        for(int i=0; i<pattern.size(); ++i ) {

            SetElement(i,pattern.at(i));

        }
    } else {
        std::cerr << "FillElements: Wrong pattern size (" << pattern.size() << " / " << GetNumberOfElements() << ")" << std::endl;
    }
}

UInt_t TH2Crystals::GetNumberOfElements()
{
    return GetNumberOfBins();
}

void TH2Crystals::SetAllBins(const Double_t value)
{
    TIter next(fBins);
    TObject *obj;
    TH2PolyBin *bin;

    while ((obj = next())) {
       bin = (TH2PolyBin*) obj;
       bin->SetContent(value);
    }
    SetBinContentChanged(kTRUE);
}
