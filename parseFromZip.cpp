
//
// Created by alitbs on 1/31/19.
//

#include <iostream>
#include "huffmanTree.h"
#include "node.h"
#include<fstream>
#include <vector>
#include "parseFromZip.h"
std::string decToBinary(int n) {
    // array to store binary number
    int binaryNum[1000];

    // counter for binary array
    int i = 0;
    while (n > 0) {

        // storing remainder in binary array
        binaryNum[i] = n % 2;
        n = n / 2;
        i++;
    }
    std::string number;
    // printing binary array in reverse order
    for (int j = i - 1; j >= 0; j--) {



        char bit = (char)(binaryNum[j]+48);
        number+=bit;
    }
    if(number.size()<8){
        std::string m ="";
        for (int j = 0; j < 8-number.size(); j++) {
            m+='0';
        }

        m+=number;
        number=m;
    }

    return number;
}
parseFromZip::parseFromZip(std::string fileMain, std::string fileTitle) {
    std::vector<std::string> words;

    std::ifstream myReadFile;
    myReadFile.open(fileTitle);

    std::string *output;
    std::string outpu;
    std::string outpu2="";
    std::vector<std::string> allStrings;
    while (getline(myReadFile, outpu, '\n'))
    {
        allStrings.push_back(outpu);


    }
    createMainList(allStrings);

    for (int i = 0; i <finalList.size() ; i++) {
      //  std::cout<<finalList.at(i).first<<": "<<finalList.at(i).second<< std::endl;
    }

    process(fileMain);

    for (int i = 0; i <allWords.size() ; i++) {
//        std::cout<<allWords.at(i);
    }
//    crate file
   createFile();
//    std::cout<<outpu2<< std::endl;

}
void parseFromZip::createMainList(std::vector<std::string> newWords) {

    std::pair<char,std::string> pair;
    char a='\n';
    pair.first=a;
    pair.second=newWords.at(0);
    finalList.push_back(pair);
    a='\t';
    pair.first=a;
    pair.second=newWords.at(1);
    finalList.push_back(pair);

    a=' ';
    pair.first=a;
    pair.second=newWords.at(2);
    finalList.push_back(pair);

    a=',';

    pair.first=a;
    pair.second=newWords.at(3);
    finalList.push_back(pair);
    a='.';

    pair.first=a;
    pair.second=newWords.at(4);
    finalList.push_back(pair);
    a='0';
    for(int i =0 ; i <10;i++){
        char help;
        help=a+i;
        pair.first=help;
        pair.second=newWords.at(i+5);
        finalList.push_back(pair);
    }

    a=':';
    pair.first=a;
    pair.second=newWords.at(15);
    finalList.push_back(pair);
     a='a';
    for(int i =0 ; i <26;i++){
        char help;
        help=a+i;
        pair.first=help;
        pair.second=newWords.at(i+16);
        finalList.push_back(pair);
    }a='A';
    for(int i =0 ; i <26;i++){
        char help;
        help=a+i;
        pair.first=help;
        pair.second=newWords.at(i+32);
        finalList.push_back(pair);
    }

}

void parseFromZip::process(std::string fileMain) {



    std::ifstream myReadFile;
    myReadFile.open(fileMain);

    std::string *output;
    std::string outpu;
    std::string outpu2="";

    std::cout <<"$$$$$$$$$$$$$$$"<<std::endl;
    if (myReadFile.is_open()) {
        char c=0;

        std::cout <<c;
        std::string charFromFile;

        std::string wordCreated;

        while (myReadFile.get(c)) {


             int m=c;
             if(m<0){
                 m=256+m;
             }
            std::cout <<c;

            charFromFile=decToBinary(m);

            wordCreated+=charFromFile;

            if(wordCreated.size()>1400){

                allWords.push_back(wordCreated);
                wordCreated="";
            }

        }
    }
    int sum=0;
    std::string decodeWord;
    std::string decodeChar="";


    std::cout <<"$$$$$$$$$$$$$$$"<<std::endl;
    std::string decodeContext;
    for (int i = 0; i <allWords.size() ; i++) {
        for (int j = 0; j < allWords.at(i).size(); j++) {
            decodeChar+=allWords.at(i).at(j);

            std::cout <<decodeChar.size()<<std::endl;
            for (int k = 0; k < finalList.size(); k++) {
                if (finalList.at(k).second == decodeChar) {

                    std::cout <<finalList.at(k).first;

                        decodeWord += finalList.at(k).first;
                        decodeChar = "";
                        break;

                    }

            }

            if (decodeWord.size() > 1400) {

                context.push_back(decodeWord);
                decodeWord = "";

            }


        }

        //std::cout <<"%%%%%%%%%%%%%%%%%%"<<std::endl;
    }

    context.push_back(decodeWord);
    for (int i = 0; i <context.size() ; i++) {

      //   std::cout <<context.at(i);


    }

    // std::cout <<sum;


}

void parseFromZip::createFile() {
//

    std::ofstream myfile ("/home/alitbs/huffman/tabitle.txt");
    if (myfile.is_open())
    {
        for (int i = 0; i < context.size(); i++) {

            myfile <<context.at(i);

        }

    }
  myfile.close();

}
