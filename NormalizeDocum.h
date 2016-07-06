#include <iostream>
#include <fstream>
#include <string.h>
#include <locale>
#include <vector>
#include <sstream>
#include <regex>
#include <dirent.h>

using namespace std;


class NormalizeDocum {
private:
    string nameDir;
    string extNormDocum = ".norm";
    string extSearchFiles=".txt";
    vector<string> listFiles;

public:

    int getDir ();
    NormalizeDocum(string );
    int normalizeFiles();
    string getNameDir() { return nameDir;}
    vector<string> getListFiles()  {return listFiles; }
    void setNameDir(string namedir) {nameDir = namedir;}    
    wchar_t cannonChar(wchar_t) ;
    ~NormalizeDocum(){};

};

