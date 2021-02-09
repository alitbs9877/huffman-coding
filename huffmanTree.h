//
// Created by alitbs on 1/31/19.
//
#include <iostream>
#include "node.h"
#include <vector>
#include <queue>
#ifndef HUFFMAN_HUFFMANTREE_H
#define HUFFMAN_HUFFMANTREE_H


class huffmanTree {
public:
    struct compare {

        bool operator()(node* l, node* r)

        {
            return (l->num > r->num);
        }
    };


    huffmanTree(){

    };
    node *root;
    //TODO need reback charatcters

    std::vector<std::pair<char,std::string> > finalList;
    std::priority_queue<node*, std::vector<node*>, compare> createdQueue;
//    void createTree(std::vector<std::pair<char,int > > list);
    void print(node * node1 , std::string str){

        if (node1==NULL) {
            return;
        }
        if (node1->data != '#') {
            //std::cout << node1->data << ": " << str << "\n";
            std::pair<char,std::string> pair;
            pair.first=node1->data;
            pair.second=str;
            finalList.push_back(pair);
        }

        print(node1->left, str + '0');
        print(node1->right, str + '1');

    }

    void createTree(std::vector<std::pair<char,int > > list) {


        node *left, *right,*current;


        for (int i = 0; i < list.size(); i++) {
            createdQueue.push(new node(list.at(i).first, list.at(i).second));
        }
        while (createdQueue.size() != 1) {


            left = createdQueue.top();
            createdQueue.pop();

            right = createdQueue.top();
            createdQueue.pop();


            left->newData.operator+=('"');

            right->newData.operator+=('!');

            current = new node('#', left->num+ right->num);

            current->left = left;
            current->right = right;

            createdQueue.push(current);
        }

        root= createdQueue.top();

    }
};


#endif //HUFFMAN_HUFFMANTREE_H
