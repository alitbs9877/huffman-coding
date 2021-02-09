//
// Created by alitbs on 1/31/19.
//

#include <iostream>
#include "node.h"
#include <vector>

#include <queue>
#include "huffmanTree.h"


//
//void huffmanTree::print(node * node1 , std::string name) {
//
//
//    if (!root) {
//        std::cout <<  "its null " << "\n";
//        return;
//    }
//    if (root->data != '$')
//        std::cout << root->data << ": " << name << "\n";
//
//    print(root->left, name + "0");
//    print(root->right, name+ "1");
//
//
//}
//
//void huffmanTree::createTree(std::vector<std::pair<char,int > > list) {
//
//
//    node *left, *right,*current;
//
//
//    for (int i = 0; i < list.size(); i++) {
//        createdQueue.push(new node(list.at(i).first, list.at(i).second));
//    }
//    while (createdQueue.size() != 1) {
//
//        left = createdQueue.top();
//        createdQueue.pop();
//
//        right = createdQueue.top();
//        createdQueue.pop();
//        left->newData.operator+=('"');
//
//        right->newData.operator+=('!');
//        current = new node('#', left->num+ right->num);
//
//        current->left = left;
//        current->right = right;
//
//        createdQueue.push(current);
//    }
//    root= createdQueue.top();
//
//
//
//}