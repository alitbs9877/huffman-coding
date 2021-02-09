//
// Created by alitbs on 1/31/19.
//

#include <iostream>
#include "huffmanTree.h"
#include "node.h"
#include<fstream>
#include <vector>
#include "parseToZip.h"

int binaryToDecimal(std::string n)
{
    std::string num = n;
    int dec_value = 0;

    int base = 1;

    int len = num.length();
    for (int i=len-1;i>=0;i--)
    {
        if (num[i] == '1')
            dec_value += base;
        base = base * 2;
    }

    return dec_value;
}
parseToZip::parseToZip(std::vector<std::string> enter) {
    std::vector<std::pair<char, int> > list;
    initCharacters();
    for (int i = 0; i <allCharacters.size() ; i++) {
        int sum=0;
        for (int j = 0; j <enter.size() ; j++) {
            for (int k = 0; k <enter.at(j).size() ; k++) {

                if(enter.at(j).at(k)==allCharacters.at(i)){
                    sum++;
                }

            }


        }
        std::pair<char,int> pair;
        pair.first=allCharacters.at(i);
        pair.second=sum;
        list.push_back(pair);

    }
    create(list);


    std::string replacedCharacter;
    std::vector<std::string> newWords;

    std::cout<<"////#######/" << std::endl;
    std::cout<<"///////////////////////////" << std::endl;

    for (int j = 0; j <enter.size() ; j++) {
        for (int k = 0; k <enter.at(j).size() ; k++) {


            std::cout<<enter.at(j).at(k);
            replacedCharacter=SwitchCase(enter.at(j).at(k) );
            if(enter.at(j).at(k)=='\n') {
            }
            newWords.push_back(replacedCharacter);
        }

        std::cout<<"////////////4444444444///" << std::endl;

    }

        int summ=0;
    for (int m = 0; m < list.size(); ++m) {

       // std::cout<<list.at(m).first <<"///  " << list.at(m).second<<   std::endl;

    }
    for (int l = 0; l <newWords.size() ; ++l) {
        summ+=newWords.at(l).size();
    }

    std::cout<<"////////////4444444444///  " <<  summ<< std::endl;

    parseToChars(newWords);
//    TODO Write To File
    createFile( newWords);
    createTitleFile();




}
void parseToZip::initCharacters() {

    char a='\n';
    allCharacters.push_back(a);

    a='\t';
    allCharacters.push_back(a);

    a=' ';
    allCharacters.push_back(a);

    a=',';
    allCharacters.push_back(a);
    a='.';
    allCharacters.push_back(a);a='0';
    for(int i =0 ; i <10;i++){
        char help;
        help=a+i;
        allCharacters.push_back(help);
    }
    a=':';
    allCharacters.push_back(a);

    a='a';
    for(int i =0 ; i <26;i++){
        char help;
        help=a+i;
        allCharacters.push_back(help);
    }a='A';
    for(int i =0 ; i <26;i++){
        char help;
        help=a+i;
        allCharacters.push_back(help);
    }


}
void parseToZip::createFile(std::vector<std::string> newWords) {


    std::ofstream myfile ("/home/alitbs/huffman/tt.txt");
    if (myfile.is_open())
    {
        for(int i =0 ; i <finalContext.size()  ; i++) {
            myfile << finalContext.at(i);
        }

    }
    myfile.close();

}

std::string parseToZip::SwitchCase(char char1) {
    for (int i = 0; i <finalList.size() ; ++i) {
        if(finalList.at(i).first==char1){
            return finalList.at(i).second;
        }
    }
}
void parseToZip::create(std::vector<std::pair<char, int> > list) {

      huffmanTree *huffmanTree1=new huffmanTree();
      huffmanTree1->createTree(list);
      huffmanTree1->print(huffmanTree1->root,"");
      finalList=huffmanTree1->finalList;
sorting();
}
void parseToZip::sorting() {


    std::vector<std::pair<char,std::string> > helpList;
    for (int i = 0; i <allCharacters.size() ; ++i) {

        for (int j = 0; j <finalList.size() ; ++j) {

            if(finalList.at(j).first==allCharacters.at(i)){
                helpList.push_back(finalList.at(j));
            }
        }
    }
    finalList=helpList;

}

void parseToZip::parseToChars(std::vector<std::string> newWords) {
    std::string codedWord;

    std::vector<std::string> allCodedWords=newWords;
//    for (int i = 0; i <finalList.size() ; i++) {
//        codedWord += finalList.at(i).second;
//        if (codedWord.size()>1400){
//            allCodedWords.push_back(codedWord);
//            codedWord="";
//        }
//    }
//    allCodedWords.push_back(codedWord);


    for (int k = 0; k <allCodedWords.size() ; ++k) {
       // std::cout<<allCodedWords.at(k);
    }
    std::string decodedWord;
    std::string eightChar;
    std::vector<std::string> allDECodedWords;
    for (int i = 0; i < allCodedWords.size(); i++) {

        for (int j = 0; j <allCodedWords.at(i).size() ; ++j) {
            eightChar+=allCodedWords.at(i).at(j);
            if(eightChar.size()==8){
                //std::cout<<eightChar<<" ** ";
                int m = binaryToDecimal(eightChar);
                eightChar="";
                char a=(char)m;

                //std::cout<<m<<std::endl;
                decodedWord+=a;

            }
            if(decodedWord.size()>1400){
                allDECodedWords.push_back(decodedWord);
                decodedWord="";
            }

        }

    }

    allDECodedWords.push_back(decodedWord);
    for (int k = 0; k <allDECodedWords.size() ; ++k) {
        std::cout<<allDECodedWords.at(k);
        finalContext.push_back(allDECodedWords.at(k));
    }


}

void parseToZip::createTitleFile() {

    std::ofstream myfile ("/home/alitbs/huffman/tt-title.txt");
    if (myfile.is_open())
    {
        for(int i =0 ; i <finalList.size()  ; i++) {
            myfile << finalList.at(i).second;
            myfile << "\n" ;
        }

    }
    myfile.close();


//    FILE* pFile;
//    pFile = fopen("file.binary", "wb");
//    for (int j = 0; j < finalList.size(); j++){
//        //Some calculations to fill a[]
//        for(int i =0 ; i < finalList.at(j).second.size() ; i++){
//
//            char a=finalList.at(j).second.at(i);
//            fwrite(a, 1, sizeof(char), pFile);
//
//        }
//    }
//    fclose(pFile);
//    return 0;
//
//
//
//    std::string str("whatever");
//    size_t size=str.size();
//    outfile.write(&size,sizeof(size);
//    outfile.write(&str[0],size);


}