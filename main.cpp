#include "NormalizeDocum.h"
#include "ClassifyDocum.h"



int main()
{
	 setlocale(LC_ALL, "ru_RU.UTF-8");
    locale::global( std::locale( "" ) );
    vector<string> files = vector<string>();
    NormalizeDocum normDocum("./files/");
    ClassifyDocum Class1("class1","./edu/class1");

    return 0;


}
