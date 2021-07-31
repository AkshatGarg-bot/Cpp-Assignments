#include "ModFile.h"

ModFile::ModFile(){}

void ModFile::setinputFilePath(std::string filePath){
    this->inputFilePath = filePath;
}

void ModFile::setoutputFilePath(std::string filePath){
    this->outputFilePath = filePath;
}

std::string ModFile::getinputFilePath(){
    return this->inputFilePath;
}

std::string ModFile::getoutputFilePath(){
    return this->outputFilePath;
}