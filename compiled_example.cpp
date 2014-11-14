#include "TH2CB.h"

#include <vector>
#include "TRint.h"

int main(int argc, char** argv) {

    // Create the application object. Pass the command line arguments through.
    TRint app( "AppTemplate", &argc, argv);

    std::vector<double> v(720);

    for(int i=0;i<v.size();++i) {
        v.at(i)=i;
    }

    TH2CB* cb = new TH2CB();
    cb->FillElements(v);
    cb->Draw("text col");

    app.Run();

    return 0;
}
