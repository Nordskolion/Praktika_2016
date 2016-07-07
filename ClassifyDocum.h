#include <iostream>
#include <fstream>
#include <string.h>
#include <map>
#include <vector>
#include <sstream>
#include "NormalizeDocum.h"
using namespace std;
typedef map <wstring,int> CountWords;

class ClassifyDocum
{
private:
	NormalizeDocum normalize;
	vector<CountWords> classCountWords;
	string nameDirClass;
	string nameClass;
	CountWords countWordsClass;
	CountWords countWordsDocum;
	int countDocumClass;


public:
	ClassifyDocum(string , string);
	//~ClassifyDocum();
	
};
