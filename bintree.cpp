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

//Temporary constructor
BinTree::BinTree(int ids[], string strings[]) {
    /* this is NOT a correct constructor,
     * you CANNOT use this assignments
     * *****************
     * this is an alternate constructor for demonstration
     * purposes only. This builds a hard coded tree
     * based on the known test data. It is simply for
     * demonstration and proving displayInOrder traversal.
     */
    root = new DataNode;
    root->left = NULL;
    root->right = NULL;
    root->data.id = ids[0];
    root->data.information = strings[0];

    root->left = new DataNode;
    root->left->left = NULL;
    root->left->right = NULL;
    root->left->data.id = ids[1];
    root->left->data.information = strings[1];

    root->right = new DataNode;
    root->right->left = NULL;
    root->right->right = NULL;
    root->right->data.id = ids[2];
    root->right->data.information = strings[2];

    root->left->right = new DataNode;
    root->left->right->left = NULL;
    root->left->right->right = NULL;
    root->left->right->data.id = ids[3];
    root->left->right->data.information = strings[3];
    
    root->left->left = new DataNode;
    root->left->left->left = NULL;
    root->left->left->right = NULL;
    root->left->left->data.id = ids[4];
    root->left->left->data.information = strings[4];
    
    root->left->right->right = new DataNode;
    root->left->right->right->left = NULL;
    root->left->right->right->right = NULL;
    root->left->right->right->data.id = ids[5];
    root->left->right->right->data.information = strings[5];
    
    root->left->right->left = new DataNode;
    root->left->right->left->left = NULL;
    root->left->right->left->right = NULL;
    root->left->right->left->data.id = ids[6];
    root->left->right->left->data.information = strings[6];

    return;
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
    displayInOrder(root);
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

void BinTree::displayPreOrder(DataNode* temproot){

};

void BinTree::displayPostOrder(DataNode* temproot){

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