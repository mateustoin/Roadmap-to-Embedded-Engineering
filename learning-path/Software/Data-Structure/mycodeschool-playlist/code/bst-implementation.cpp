#include <iostream>
#include <algorithm>

using namespace std;

struct BstNode {
    int data;
    BstNode* left;
    BstNode* right;
};

BstNode* GetNewNode(int data);
BstNode* Insert(BstNode* root, int data);
bool Search(BstNode* root, int data);
void preorder(BstNode* root);
void inorder(BstNode* root);
void postorder(BstNode* root);
int minRecursive(BstNode* root);
int maxRecursive(BstNode* root);
int maxIterative(BstNode* root);
int minIterative(BstNode* root);
int height(BstNode* root);

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
    root = Insert(root, 14);

    inorder(root);

    cout << "Max value of tree: " << maxIterative(root) << endl;
    cout << "Min value of tree: " << minIterative(root) << endl;
    cout << "Height of tree: " << height(root) << endl;

    /*
    int searchNumber = 0;
    cout << "Search a data in tree: ";
    cin >> searchNumber;
    cout << endl;

    if (Search(root, searchNumber))
        cout << "Number found in tree" << endl;
    else
        cout << "Number not found in tree" << endl;
    */
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

void preorder(BstNode* root) {
    if (root != NULL) {
        cout << root->data << endl;
        preorder(root->left);
        preorder(root->right);
    }
}

void inorder(BstNode* root) {
    if (root != NULL) {
        inorder(root->left);
        cout << root->data << endl;
        inorder(root->right);
    }
}

void postorder(BstNode* root) {
    if (root != NULL) {
        postorder(root->left);
        postorder(root->right);
        cout << root->data << endl;
    }
}

int minRecursive(BstNode* root) {
    if (root->left != NULL)
        minRecursive(root->left);
    else
        return root->data;
}

int maxRecursive(BstNode* root) {
    if (root->right != NULL)
        maxRecursive(root->right);
    else
        return root->data;
}

int maxIterative(BstNode* root) {
    while(root->right != NULL){
        root = root->right;
    }

    return root->data;
}

int minIterative(BstNode* root) {
    while(root->left != NULL){
        root = root->left;
    }

    return root->data;
}

int height(BstNode* root) {
    if (root == NULL)
        return -1;

    return max(height(root->left), height(root->right)) + 1;
}