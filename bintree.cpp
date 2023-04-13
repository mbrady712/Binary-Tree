/*
Name: Michael Brady
Programming Fundamentals III
Purpose: This program creates a Binary Search Tree ADT
*/

#include "bintree.h"

BinTree::BinTree(){
    root = NULL;
    count = 0;
}

BinTree::~BinTree(){
    clear();
}

bool BinTree::isEmpty(){
    return true;
}

int BinTree::getCount(){
    return 0;
}

bool BinTree::getRootData(Data* data){
    return true;
};

void BinTree::displayTree(){
    displayPreOrder();
    displayInOrder();
    displayPostOrder();
};

//Public methods with private overloads

void BinTree::clear(){

};

bool BinTree::addNode(int id, const string* information){
    bool added = false;
    if(id > 0 && *information != ""){
        Data *newNode = new Data;
        newNode->id = id;
        newNode->information = *information;
        DataNode *newDataNode = new DataNode;
        newDataNode->data = *newNode;
        newDataNode->left = NULL;
        newDataNode->right = NULL;
        added = addNode(newDataNode, &root);
        if(added){
            count++;
        }
    }
    return added;
};

bool BinTree::removeNode(int id){
    return true;
};

bool BinTree::getNode(Data* data, int id){
    return true;
};

bool BinTree::contains(int id){
    return true;
};

int BinTree::getHeight(){
    return 0;
};

void BinTree::displayPreOrder(){
    displayPreOrder(root);
};

void BinTree::displayPostOrder(){
    displayPostOrder(root);
};

void BinTree::displayInOrder(){
    displayInOrder(root);
};

//Overloads of public methods
void BinTree::clear(DataNode* node){

};

bool BinTree::addNode(DataNode* newNode, DataNode** root){
    bool added = false;
    if(!(*root)){
        *root = newNode;
        added = true;
    }
    else if(newNode->data.id < (*root)->data.id){
        added = addNode(newNode, &(*root)->left);
    }else if(newNode->data.id > (*root)->data.id){
        added = addNode(newNode, &(*root)->right);
    }
    return added;
};

DataNode* BinTree::removeNode(int id, DataNode* node){
    return node;
};

bool BinTree::getNode(Data* data, int id, DataNode* node){
    return true;
};

bool BinTree::contains(int id, DataNode* node){
    return true;
};

int BinTree::getHeight(DataNode* node){
    return 0;
};

void BinTree::displayPreOrder(DataNode* temproot){

    if (temproot) {
        cout << temproot->data.id << " " << temproot->data.information << endl;
        if (temproot->left) {
            displayPreOrder(temproot->left);
        }
        if (temproot->right) {
            displayPreOrder(temproot->right);
        }
    }

    return;

};

void BinTree::displayPostOrder(DataNode* temproot){

    if (temproot) {
        if (temproot->left) {
            displayPostOrder(temproot->left);
        }
        if (temproot->right) {
            displayPostOrder(temproot->right);
        }
        cout << temproot->data.id << " " << temproot->data.information << endl;
    }

    return;

};

void BinTree::displayInOrder(DataNode* temproot){

    if (temproot) {
        if (temproot->left) {
            displayInOrder(temproot->left);
        }
        cout << temproot->data.id << " " << temproot->data.information << endl;
        if (temproot->right) {
            displayInOrder(temproot->right);
        }
    }

    return;
};