#include <iostream>
#include <fstream>
#include <string.h>
#include <map>
#include <vector>
#include <sstream>
#include "NormalizeDocum.h"
using namespace std;
typedef map <wstring,int> CountWords;
typedef map <wstring,double> DfIdf; 
class ClassifyDocum
{
private:
	NormalizeDocum  * normalize;
	vector<CountWords> classCountWords;
	string nameDirClass;
	string nameClass;
	CountWords countWordsClass;
	CountWords countWordsDocum;
	vector<string> listFiles;
	int countDocumClass;
	DfIdf weightWordsClass;

public:
	ClassifyDocum(string , string);
	//~ClassifyDocum();
	void calculateWords();
	void calculateWeight();
	
};
