#include "NormalizeDocum.h"



NormalizeDocum::NormalizeDocum(string namedir) {
    nameDir = namedir;
    extSearchFiles = ".txt";
    getDir();

}


int NormalizeDocum::getDir ()
{
    DIR *dp;
    struct dirent *dirp;

    if((dp  = opendir(nameDir.c_str())) == NULL) {
        cout << "Error(" << errno << ") opening " << nameDir << endl;
        return errno;
    }

    while ((dirp = readdir(dp)) != NULL) {
        if(!strcmp( dirp->d_name, "." )) continue;
        if(!strcmp( dirp->d_name, ".." )) continue;
        if ( strstr( dirp->d_name, extSearchFiles.c_str() ))
            listFiles.push_back(string(dirp->d_name));
    }
    closedir(dp);
    return 0;
}

