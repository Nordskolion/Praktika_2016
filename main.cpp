
#include "ClassifyDocum.h"



int main()
{
	setlocale(LC_ALL, "");
    locale::global( std::locale( "" ) );
    ios_base::sync_with_stdio(false);
    wcout.imbue(locale(""));

	 // setlocale(LC_ALL, "ru_RU.UTF-8");
  //   locale::global( std::locale( "" ) );
    string rootDirEdu="./edu/";
    string rootDirDocum = "./docum/";

    NormalizeDocum dirEdu(rootDirEdu);
    dirEdu.scanDir();
    vector<string> files = dirEdu.getListDir();
    vector<ClassifyDocum *> classEdu;

    // cout<<files.size()<<"::size"<<endl;
    for(size_t i=0; i < files.size(); i++)
    {
     // cout<<files[i]<<"========================================================"<<endl;
     // classEdu.push_back(new ClassifyDocum(files[i],rootDirEdu+files[i]+"/"));
      // cout<<rootDirEdu+files[i]<<endl;
    } 
    ClassifyDocum classDocum("Docum",rootDirDocum); 
    for(size_t i=0; i < classEdu.size(); i++)
    {
     classDocum.calculateDistance(*classEdu[i]);
    }

    

    return 0;


}
