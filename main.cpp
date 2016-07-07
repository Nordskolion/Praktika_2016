
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
    Class1.calculateWords();
    Class1.calculateWeight();
    return 0;


}
