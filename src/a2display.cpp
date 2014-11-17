#include "a2display.h"
#include "TDirectory.h"
#include "TIterator.h"
#include <iostream>

using namespace std;

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

void TH2Crystals::SetElements(const std::vector<Double_t> &pattern)
{

    if(pattern.size()==GetNumberOfElements()) {

        for(int i=0; i<pattern.size(); ++i ) {

            SetElement(i,pattern.at(i));

        }
    } else {
        std::cerr << "FillElements: Wrong pattern size (" << pattern.size() << " / " << GetNumberOfElements() << ")" << std::endl;
    }
}

void TH2Crystals::SetElements(const TH1 &h)
{
    if( h.GetNbinsX() == GetNumberOfElements() ) {
        TIter next(fBins);
        TObject *obj;
        TH2PolyBin *bin;
        Int_t hbin=1;
        while ((obj = next())) {
           bin = (TH2PolyBin*) obj;
           bin->SetContent(h.GetBinContent(hbin++));
        }
        SetBinContentChanged(kTRUE);
    } else {
        cerr << "Number of bis don't match" << endl;
    }
}

void TH2Crystals::FillElement(const UInt_t element, const Double_t w)
{
    SetElement( element, GetElement(element) + w);
}

void TH2Crystals::FillElements(const std::vector<Double_t> &pattern)
{
    if(pattern.size()==GetNumberOfElements()) {

        for(int element=0; element<pattern.size(); ++element ) {

            FillElement(element, pattern.at(element));

        }
    } else {
        std::cerr << "FillElements: Wrong pattern size (" << pattern.size() << " / " << GetNumberOfElements() << ")" << std::endl;
    }
}

void TH2Crystals::FillElements(const TH1 &h)
{
    if( h.GetNbinsX() == GetNumberOfElements() ) {
        TIter next(fBins);
        TObject *obj;
        TH2PolyBin *bin;
        Int_t hbin=1;
        while ((obj = next())) {
           bin = (TH2PolyBin*) obj;
           bin->SetContent( bin->GetContent() + h.GetBinContent(hbin++));
        }
        SetBinContentChanged(kTRUE);
    } else {
        cerr << "Number of bis don't match" << endl;
    }
}

UInt_t TH2Crystals::GetNumberOfElements() const
{
    return GetNumberOfBins();
}

void TH2Crystals::ResetElements(const Double_t value)
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
