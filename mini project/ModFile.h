#ifndef MODFILE_H_INCLUDED
#define MODFILE_H_INCLUDED

#include <iostream>

class ModFile{
    private:
        std::string inputFilePath;
        std::string outputFilePath;
    public:
        ModFile();
        void ModifyFile();
        void setinputFilePath(std::string);
        void setoutputFilePath(std::string);
        std::string getinputFilePath();
        std::string getoutputFilePath();

};


#endif // MODFILE_H_INCLUDED
