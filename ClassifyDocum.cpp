#include "ClassifyDocum.h"


ClassifyDocum::ClassifyDocum(string nameclass ,string namedirclass) // конструктор , сразу нормализует документы 
{
	countAllWords = 0;
	nameClass=nameclass;
	nameDirClass = namedirclass;
	normalize = new NormalizeDocum(nameDirClass);
	listFiles = normalize->getListFiles();
	countAllFiles = listFiles.size();
	// cout<<listFiles.size()<<endl;

}

void ClassifyDocum::calculateWords() //читать класс 
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
             countAllWords++;
         }
         fileId.close();
         classCountWords.push_back(countWordsClass);
    }
    for (CountWords::iterator p = countWordsClass.begin(); p != countWordsClass.end(); ++p) {
                      // wcout << p->first << ": " << p->second << '\n';
         }
}

void ClassifyDocum::calculateWeight()//Вес
{
	cout.precision(17);
	double j;
	for(CountWords::iterator p = countWordsClass.begin(); p != countWordsClass.end(); ++p)
	{
		// cout << j<< "  " << p->second <<endl;
		j = (double)p->second/countAllWords;
		weightWordsClass.insert(pair<wstring,double>(p->first,j));
	}
	 for (DfIdf::iterator p = weightWordsClass.begin(); p != weightWordsClass.end(); ++p) {
                      	wcout << p->first << ": " << p->second << '\n' ;
         }
}