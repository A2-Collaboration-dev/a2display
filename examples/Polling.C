void Polling() 
{

    int loaded = gSystem->Load("../build/liba2display.so");
    if(loaded != 0) {
        cerr << "Could not load liba2display.so\nRun from inside example folder." << endl;
    }

    TH1D* Hits = new TH1D("NaI_Hits","NaI Hits",720,0,720);

    TTimer* data_maker = new TTimer("NaI_Hits->FillRandom(\"gaus\",1)",1000);
    data_maker->Start();

    PollingHistogram<TH2CB>* cb = new PollingHistogram<TH2CB>("NaI_Hits","NaI_update","Self Updating from NaI_Hits");
    cb->Draw("col");

    TTimer* cb_updater = new TTimer("NaI_update->Draw()",2000);
    cb_updater->Start();

    cb->Draw();



}
