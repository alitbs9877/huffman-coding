#include <iostream>
#include "huffmanTree.h"
#include "node.h"
#include<fstream>
#include <vector>
#include "parseFromZip.h"

#include "parseFromZip.cpp"
#include "parseToZip.cpp"

#include "parseToZip.h"



int main() {
    std::cout<<"read(1) or write(2) ?"<< std::endl;
    std::cout << "Hello, World!" << std::endl;
//      huffmanTree *huffmanTree1=new huffmanTree();
//
//       std::vector<std::pair<char,int > > list;
//      std::pair<char,int> pair1;
//      pair1.first= 'a';
//      pair1.second = 5;
//      list.push_back(pair1);
//      pair1.first= 'b';
//      pair1.second = 9;
//      list.push_back(pair1);
//
//      pair1.first= 'c';
//      pair1.second = 12;
//      list.push_back(pair1);
//      pair1.first= 'd';
//      pair1.second =13 ;
//      list.push_back(pair1);
//      pair1.first= 'e';
//      pair1.second = 16;
//      list.push_back(pair1);
//      pair1.first= 'f';
//      pair1.second = 45;
//      list.push_back(pair1);
//      node *a=new node('a',2);
//      //huffmanTree1->root=a;
//      //huffmanTree1->a2(list);
//      huffmanTree1->createTree(list);
//      huffmanTree1->print(huffmanTree1->root,"");


    //    int enter;
//    std::cin >> enter;
//    if(enter==1){
        std::cout<<"your pathFile"<< std::endl;
        std::ifstream myFile;
        myFile.open("/home/alitbs/huffman/tet.txt");
        std::string help;
        std::string outPut;
        std::vector<std::string> context;
        while(getline(myFile,help, '\n')){
            if(outPut.size()>1400){
                context.push_back(outPut);
                outPut="";
            }
            outPut+=help;
            outPut+='\n';

        }
        context.push_back(outPut);
    for (int i = 0; i <context.size() ; ++i) {
        std::cout<<context.at(i)<<std::endl;
    }
        parseToZip *Zipper= new parseToZip(context);

//
//
//    }
//    if(enter==2){

        std::cout<<"your pathFile"<< std::endl;
        std::string mainFile="/home/alitbs/huffman/tt.txt";
        std::string TitleFile="/home/alitbs/huffman/tt-title.txt";

        parseFromZip *UnZipper = new parseFromZip(mainFile,TitleFile);


//
//    }


    /*
     *
int main()
{*/
//    std::ofstream OutFile ;
//    OutFile.open("/home/alitbs/huffman/abb.b", std::ios::out | std::ios::binary);
//    std::string n="ali Tabasi";
//    int size=n.size();
//    OutFile.write( (char*)&n, size*sizeof(std::string));
//    OutFile.close();
//
//
//    std::ofstream myfile ("/home/alitbs/huffman/tabitle.txt");
//    if (myfile.is_open())
//    {
//            myfile <<n;
//
//
//    }
//    myfile.close();



    return 0;
}