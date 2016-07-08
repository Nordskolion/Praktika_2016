
#include "ClassifyDocum.h"



int main()
{
	setlocale(LC_ALL, "");
    locale::global( std::locale( "" ) );
    ios_base::sync_with_stdio(false);
    wcout.imbue(locale(""));

	 // setlocale(LC_ALL, "ru_RU.UTF-8");
  //   locale::global( std::locale( "" ) );
    vector<string> files = vector<string>();
    NormalizeDocum normDocum("./files/");
    ClassifyDocum Class1("class1","./edu/class1/");
    ClassifyDocum Class2("class2","./edu/class2/");
    Class1.calculateWords();
    Class1.calculateWeight();
    Class1.calculateDistance(Class2);
    return 0;


}
