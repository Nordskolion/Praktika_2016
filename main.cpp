
#include "ClassifyDocum.h"



int main()
{
	setlocale(LC_ALL, "");
    locale::global( std::locale( "" ) );
    ios_base::sync_with_stdio(false);
    wcout.imbue(locale(""));

    string rootDirEdu="./edu/";
    string rootDirDocum = "./docum/";

    NormalizeDocum dirEdu(rootDirEdu);
    dirEdu.scanDir();
    vector<string> files = dirEdu.getListDir();
    vector<ClassifyDocum *> classEdu;

    for(size_t i=0; i < files.size(); i++)
    {
     classEdu.push_back(new ClassifyDocum(files[i],rootDirEdu+files[i]+"/"));
    } 
    ClassifyDocum classDocum("Docum",rootDirDocum); 
    classDocum.whileCalculate(classEdu);

    

    return 0;


}
