//
// Created by alitbs on 1/31/19.
//
#include <iostream>
#include "huffmanTree.h"
#include "node.h"
#include<fstream>
#include <vector>
#ifndef HUFFMAN_PARSETOZIP_H
#define HUFFMAN_PARSETOZIP_H


class parseToZip {
public:

    parseToZip(std::vector<std::string > enter);
    std::vector<std::pair<char,std::string> > finalList;

    std::vector<std::string> finalContext;
    std::vector<char> allCharacters;
    void initCharacters();
    FILE finalFile;
    void create(std::vector<std::pair<char,int > > list);
    std::string SwitchCase(char char1);
    void createFile(std::vector<std::string> newWords);
    void createTitleFile();
    void sorting();
    void parseToChars(std::vector<std::string> newWords);


};


#endif //HUFFMAN_PARSETOZIP_H
