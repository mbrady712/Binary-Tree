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

};

//Public methods with private overloads

void BinTree::clear(){

};

bool BinTree::addNode(int id, const string* information){
    return true;
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

};

void BinTree::displayPostOrder(){

};

void BinTree::displayInOrder(){
    
};

//Overloads of public methods
void BinTree::clear(DataNode* node){

};

bool BinTree::addNode(DataNode* node, DataNode** nodeptr){
    return true;
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

void BinTree::displayPreOrder(DataNode* node){

};

void BinTree::displayPostOrder(DataNode* node){

};

void BinTree::displayInOrder(DataNode* node){

};