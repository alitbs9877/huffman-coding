//
// Created by alitbs on 1/31/19.
//
#include <iostream>


#ifndef HUFFMAN_NODE_H
#define HUFFMAN_NODE_H


class node {
public:
    char data;


    unsigned int num;
    std::string newData;

    node *left, *right;

    node(char data, unsigned int num) {

        left = right = NULL;
        this->data = data;
        this->num=num;
        this->newData="";


    };
};


#endif //HUFFMAN_NODE_H
