
//
// Created by alitbs on 1/31/19.
//

#ifndef HUFFMAN_PARSEFROMZIP_H
#define HUFFMAN_PARSEFROMZIP_H


#include <iostream>
#include "huffmanTree.h"
#include "node.h"
#include<fstream>
#include <vector>

class parseFromZip {
public:
    std::vector<std::pair<char,std::string> > finalList;
    std::vector<std::string> allWords;
    std::vector<std::string> context;
    void process(std::string fileMain);

    parseFromZip(std::string fileMain,std::string fileTitle);
    void createMainList(std::vector<std::string> newWords);

    void createFile();




};


#endif //HUFFMAN_PARSEFROMZIP_H
