
#include "ClassifyDocum.h"


void whileCalculate(string , string);
int main()
{
	setlocale(LC_ALL, "");
    locale::global( std::locale( "" ) );
    ios_base::sync_with_stdio(false);
    wcout.imbue(locale(""));

    string rootDirEdu="./edu/";
    string rootDirDocum = "./docum/";

    // NormalizeDocum dirEdu(rootDirEdu);
    // NormalizeDocum dirDocum(rootDirDocum);
    // dirDocum.scanListFiles();
    // dirEdu.scanDir();
    // vector<string> files = dirEdu.getListDir();
    // vector<ClassifyDocum *> classEdu;


    // // for(size_t i=0; i < files.size(); i++)
    // {
    //  classEdu.push_back(new ClassifyDocum(files[i],rootDirEdu+files[i]+"/"));
    // } 
    // ClassifyDocum classDocum("Docum",rootDirDocum); 
    // classDocum.whileCalculate(rootDirDocum,rootDirEdu);
    whileCalculate(rootDirDocum,rootDirEdu);
    

    return 0;


}





void whileCalculate(string rootDirDocum,string rootDirEdu )
{
    double x = 0;
    NormalizeDocum dirEdu(rootDirEdu);
    NormalizeDocum dirDocum(rootDirDocum);
    dirDocum.scanListFiles();
    vector<string> listFiles=dirDocum.getListFiles();
    dirEdu.scanDir();
    vector<string> files = dirEdu.getListDir();
    vector<ClassifyDocum *> classEdu;
     for(size_t i=0; i < files.size(); i++)
    {
     classEdu.push_back(new ClassifyDocum(files[i],rootDirEdu+files[i]+"/"));
    } 

    for (size_t i = 0; i<listFiles.size(); i++)
    {
       ClassifyDocum docum(listFiles[i] , rootDirDocum , listFiles[i]);
    
    for(size_t i=0; i < classEdu.size(); i++)
    {
     x = docum.calculateDistance(*classEdu[i]);
    }
  }
}