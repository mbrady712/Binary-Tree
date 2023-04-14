/*
Name: Michael Brady
Programming Fundamentals III
Purpose: This program creates a Binary Search Tree ADT
*/

#ifndef BINTREE_BINTREE_H
#define BINTREE_BINTREE_H

#include "data.h"
#include <iostream>

using std::cout;
using std::endl;

class BinTree{
    public:
        BinTree();
        ~BinTree();
        bool isEmpty();
        int getCount();
        bool getRootData(Data*);
        void displayTree();
        //Public methods with private overloads
        void clear();
        bool addNode(int, const string*);
        bool removeNode(int);
        bool getNode(Data*, int);
        bool contains(int);
        int getHeight();
        void displayPreOrder();
        void displayPostOrder();
        void displayInOrder();
    private:
        //Attributes
        DataNode* root;
        int count;
        //Overloads of public methods
        void clear(DataNode*);
        bool addNode(DataNode*, DataNode**);
        DataNode* removeNode(int, DataNode*);
        bool getNode(Data*, int, DataNode*);
        bool contains(int, DataNode*);
        int getHeight(DataNode*);
        void displayPreOrder(DataNode*);
        void displayPostOrder(DataNode*);
        void displayInOrder(DataNode*);
        //Purely private methods
        DataNode* minValueNode(DataNode*);

};

#endif /* BINTREE_BINTREE_H */

