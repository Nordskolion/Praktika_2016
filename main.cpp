#include "NormalizeDocum.h"




int main()
{
	 setlocale(LC_ALL, "ru_RU.UTF-8");
    locale::global( std::locale( "" ) );
    vector<string> files = vector<string>();
    NormalizeDocum normDocum("./files/");
    return 0;


}
