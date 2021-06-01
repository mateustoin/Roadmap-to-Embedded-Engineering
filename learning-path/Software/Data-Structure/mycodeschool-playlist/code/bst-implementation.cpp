#include <iostream>

using namespace std;

struct BstNode {
    int data;
    BstNode* left;
    BstNode* right;
};

BstNode* GetNewNode(int data);
BstNode* Insert(BstNode* root, int data);
bool Search(BstNode* root, int data);

BstNode *root = NULL;

int main() {
    root = Insert(root, 10);
    root = Insert(root, 15);
    root = Insert(root, 25);
    root = Insert(root, 46);
    root = Insert(root, 3);
    root = Insert(root, 9);
    root = Insert(root, 110);
    root = Insert(root, -43);

    int searchNumber = 0;
    cout << "Search a data in tree: ";
    cin >> searchNumber;
    cout << endl;

    if (Search(root, searchNumber))
        cout << "Number found in tree" << endl;
    else
        cout << "Number not found in tree" << endl;

    return 0;
}


/*
 * FUNCTIONS IMPLEMENTATION
 */

BstNode* GetNewNode(int data){
    BstNode* newNode = new BstNode();
    newNode->data=data;
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}

BstNode* Insert(BstNode* root, int data) {
    // If it is a empty tree
    if (root == NULL) {
        root = GetNewNode(data);
        return root;
    }
    // If the tree is not empty, test if data is bigger or smaller
    // to know if we'll create a left or right node in the subtree
    else if(data <= root->data){
        root->left = Insert(root->left, data);
    }
    else{
        root->right = Insert(root->right, data);
    }

    return root;
}

bool Search(BstNode* root, int data) {
    //If it is a empty tree, return false right away
    if (root == NULL)
        return false;
    //If we have found the node with the same data, return true 
    if (root->data == data)
        return true;
    //If not, search for the data based on the value
    if (data <= root->data){
        return Search(root->left, data);
    }else{
        return Search(root->right, data);
    }
}