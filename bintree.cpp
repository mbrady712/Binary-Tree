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
    cout << "DISPLAY TREE" << endl;
    cout << "==============================================" << endl;
    cout << endl;
    cout << "Pre-Order Traversal" << endl;
    displayPreOrder();
    cout << endl;
    cout << "In-Order Traversal" << endl;
    displayInOrder();
    cout << endl;
    cout << "Post-Order Traversal" << endl;
    displayPostOrder();
    cout << endl;
    cout << "==============================================" << endl;
};

//Public methods with private overloads

void BinTree::clear(){
    clear(root);
    root = NULL;
    count = 0;
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
    bool removed = false;
    int tempcount = count;
    root = removeNode(id, root);
    if(count < tempcount){
        removed = true;
    }
    return removed;
};

bool BinTree::getNode(Data* data, int id){
    bool retrieved = false;
    if(id > 0){
        retrieved = getNode(data, id, root);
    }
    return retrieved;
};

bool BinTree::contains(int id){
    bool inTree = false;
    if(id > 0){
        inTree = contains(id, root); 
    }
    return inTree;
};

int BinTree::getHeight(){
    return getHeight(root);
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
void BinTree::clear(DataNode* temproot){
    
    if(temproot){
        clear(temproot->left);
        clear(temproot->right);
        temproot->left = NULL;
        temproot->right = NULL;
        delete temproot;
    }
    return;
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

DataNode* BinTree::removeNode(int id, DataNode* temproot){
    if(temproot){
        if(id < temproot->data.id){
            temproot->left = removeNode(id, temproot->left);
        }else if(id > temproot->data.id){
            temproot->right = removeNode(id, temproot->right);
        }else{
            DataNode *temp = new DataNode;
            if(temproot->left == NULL){
                temp = temproot->right;
                delete temproot;
                temproot = temp;
                count--;
            }else if(temproot->right == NULL){
                temp = temproot->left;
                delete temproot;
                temproot = temp;
                count--;
            }else{
                temp = minValueNode(temproot->right);
                temproot->data.id = temp->data.id;
                temproot->data.information = temp->data.information;
                temproot->right = removeNode(temp->data.id, temproot->right);
            }
        }
    }
    return temproot;
};

bool BinTree::getNode(Data* data, int id, DataNode* temproot){
    bool retrieved = false;
    if(temproot){
        if(temproot->data.id == id){
            data->id = temproot->data.id;
            data->information = temproot->data.information;
            retrieved = true;
        }else if(id < temproot->data.id){
            retrieved = getNode(data, id, temproot->left);
        }
        else if(id > temproot->data.id){
            retrieved = getNode(data, id, temproot->right);
        }
    }
    return retrieved;
};

bool BinTree::contains(int id, DataNode* temproot){
    bool inTree = false;
    if(temproot){
        if(temproot->data.id == id){
            inTree = true;
        }else if(id < temproot->data.id){
            inTree = contains(id, temproot->left);
        }
        else if(id > temproot->data.id){
            inTree = contains(id, temproot->right);
        }
    }
    return inTree;
};

int BinTree::getHeight(DataNode* temproot){
    int lh = 0;
    int rh = 0;
    int height = 0;
    if(temproot){
        lh = getHeight(temproot->left);
        rh = getHeight(temproot->right);
        height = ((lh<rh)?rh:lh) + 1;
    }
    return height;
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

DataNode* BinTree::minValueNode(DataNode* node) {
    DataNode* current = node;
    while (current && current->left != NULL) {
        current = current->left;
    }
    return current;
}