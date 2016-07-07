#include "ClassifyDocum.h"


ClassifyDocum::ClassifyDocum(string nameclass ,string namedirclass)
{
	nameClass=nameclass;
	nameDirClass = namedirclass;
	normalize = new NormalizeDocum(nameDirClass);
	listFiles = normalize->getListFiles();
	// cout<<listFiles.size()<<endl;

}

void ClassifyDocum::calculateWords()
{
	 for(size_t i=0; i<listFiles.size();i++) 
	 {
      	wifstream fileId(nameDirClass+listFiles[i]+".norm");
	 	cout<<listFiles.size()<<"  i:"<<i<<endl;;
        wstring strInput;   
        cout<<"NewFIle : "<<listFiles[i]<<endl;
        while(fileId>>strInput) 
        {
             //wcout <<strInput<<"====\n";
             ++countWordsClass[strInput];
         }
         fileId.close();
         classCountWords.push_back(countWordsClass);
    }
    for (CountWords::iterator p = countWordsClass.begin(); p != countWordsClass.end(); ++p) {
                      wcout << p->first << ": " << p->second << '\n';
         }
}

void ClassifyDocum::calculateWeight()
{
	for(CountWords::iterator p = countWordsClass.begin(); p != countWordsClass.end(); ++p)
	{
		DfIdf.insert(pair<wstring,double>(p->first,p->second));
	}
}