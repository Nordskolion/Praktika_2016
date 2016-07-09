#include "ClassifyDocum.h"


ClassifyDocum::ClassifyDocum(string nameclass ,string namedirclass) // конструктор , сразу нормализует документы
{
	countAllWords = 0;
	nameClass=nameclass;
	nameDirClass = namedirclass;
	normalize = new NormalizeDocum(nameDirClass);
	normalize->scanListFiles();
	normalize->normalizeFiles();
	listFiles = normalize->getListFiles();
	countAllFiles = listFiles.size();
	calculateWords();
	calculateWeight();
	cout<<listFiles.size()<<endl;

}

void ClassifyDocum::calculateWords() //читать класс
{
	cout<<getName()<<"  "<<listFiles.size()<<endl;
	 for(size_t i=0; i<listFiles.size();i++)
	 {
      	wifstream fileId(nameDirClass+listFiles[i]+".norm");
	 	// cout<<listFiles.size()<<"  i:"<<i<<endl;;
        wstring strInput;
        // cout<<"NewFIle : "<<listFiles[i]<<endl;
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
		   // j = p->second;
		weightWordsClass.insert(pair<wstring,double>(p->first,j));
	}
	 for (DfIdf::iterator p = weightWordsClass.begin(); p != weightWordsClass.end(); ++p) {
                      	 wcout << p->first << ": " << p->second << '\n' ;
         }
}
double ClassifyDocum::calculateDistance(ClassifyDocum theme)
{
	// wcout<<"ZASHEL"<<endl;
	double x = 0;
	int countCondition = 0;
	DfIdf weight1 = theme.getWeightWordsClass();

	for (DfIdf::iterator k = weightWordsClass.begin(); k != weightWordsClass.end(); ++k) {
            			if(weight1[k->first])
                      	{                        
                        	x = (double)((x+(double)(k->second+weight1[k->first])));
                        	countCondition++;
                        	// wcout << theme.getName().c_str() << "  "<< p->first <<  " ======= "<< p->second << '\n' ;
                        	// wcout <<  weight1[k->first] << "  "<< k->first <<" ======= "<<k->second << '\n' ;
                        }
					}
	x = (double)x/2;
	wcout << "========================================" << endl << x << "   " << theme.getName().c_str() << "    " << nameClass.c_str() <<endl;
	return x;
}
