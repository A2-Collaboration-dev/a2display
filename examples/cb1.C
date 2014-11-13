void cb1() 
{

    int loaded = gSystem->Load("../build/liba2display.so");
    if(loaded != 0) {
        cerr << "Could not load liba2display.so\nRun from inside example folder." << endl;
    }

    using namespace a2::display;

    TH2CB* cb = new TH2CB();

    cb->FillElementNumber();
    cb->SetHoles(0);

    cb->Draw("text col");
}
