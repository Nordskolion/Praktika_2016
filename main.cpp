
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
    ClassifyDocum Class3("class3","./edu/class3/");
    ClassifyDocum Class4("class4","./edu/class4/");
    ClassifyDocum Class5("class5","./edu/class5/");
    ClassifyDocum Class6("class6","./edu/class6/");
    ClassifyDocum Class7("elemnt","./edu/class7/");

    // Class1.calculateWords();
    // Class1.calculateWeight();
    Class1.calculateDistance(Class7);
    Class2.calculateDistance(Class7);
    Class3.calculateDistance(Class7);
    Class4.calculateDistance(Class7);
    Class5.calculateDistance(Class7);
    Class6.calculateDistance(Class7);

    return 0;


}
