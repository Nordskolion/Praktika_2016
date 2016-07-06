#include "NormalizeDocum.h"




int main()
{

    vector<string> files = vector<string>();
    NormalizeDocum normDocum("./files/");
    cout<<normDocum.getNameDir()<<endl;
    files = normDocum.getListFiles();

   for (unsigned int i = 0;i < files.size();i++) {
       cout << files[i] << endl;
    }
    return 0;


}
