#include "ClassifyDocum.h"


ClassifyDocum::ClassifyDocum(string nameclass ,string namedirclass)
{
	nameClass=nameclass;
	nameDirClass = namedirclass;
	normalize = new NormalizeDocum(nameDirClass);
	listFiles = normalize->getListFiles();
	// cout<<listFiles.size()<<endl;

}

CountWords ClassifyDocum::calculateWords()
{
	 for(size_t i=0; i<listFiles.size();i++) {
      //  wifstream fileId(listFiles[i]);
        wstring strInput;   
        CountWords numWords;
        cout<<"NewFIle : "<<listFiles[i]<<endl;
        // while(fileId>>strInput) {
        //      //wcout <<strInput<<"====\n";
        //      ++numWords[strInput];
        //  }
        //  fileId.close();
        //  classCountWords.push_back(numWords);
        //  for (CountWords::iterator p = numWords.begin(); p != numWords.end(); ++p) {
             // wcout << p->first << ": " << p->second << '\n';
         // }
    }
}
