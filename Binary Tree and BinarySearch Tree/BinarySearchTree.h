#include<iostream>
using namespace std;
class BST {
    private:
    BinaryNode<int>* root;

    public:
    BinaryNode<int>* getRoot()
    {
        return root;
    }

    public:
    void setRoot(BinaryNode<int>* node) {
        root = node;
    }


    public:
    BST() {
        root = nullptr;
    }

    ~BST() {
        delete root;
    }
    public:
    void deleteData(int data) {
        root = deleteData(data, root);
    }
    private:
    BinaryNode<int>* deleteData(int data, BinaryNode<int>* node) {
        if(root == nullptr)
            return nullptr;
        if(data > node->data)
        {
            node->right = deleteData(data, node->right);
            return node;
        }
        else if(data < node->data) {
            node->left = deleteData(data, node->left);
            return node;
        }
        else {
            if(node->left == nullptr && node->right == nullptr)
            {
                delete node;
                return nullptr;
            }
            else if(node->left == nullptr) {
                BinaryNode<int>* temp = node->right;
                node->right = nullptr;
                delete node;
                return temp;
            }
            else if(node->right == nullptr)
            {
                BinaryNode<int>* temp = node->left;
                node->left = nullptr;
                delete node;
                return temp;
            }
            else {
                BinaryNode<int>* minNode = node->right;
                while(minNode->left!=nullptr) {
                    minNode = minNode->left;
                }
                int rightMin = minNode->data;
                node->data = rightMin;
                node->right = (rightMin, node->right);
                return node;
            }
        }
        
    }
    public:
    void insertData(int data)
    {
        this->root = insertHelper(data, this->root);
    }

    private:
    BinaryNode<int>* insertHelper(int data, BinaryNode<int>* node) {
        if(node == nullptr)
        {
            BinaryNode<int>* newNode = new BinaryNode<int>(data);
            return newNode;
        }

        if(data < node->data) {
            node->left = insertHelper(data, node->left);
        }
        else {
            node->right = insertHelper(data, node->right);
        }
        return node;

    }



    bool hasData(int data, BinaryNode<int>* node) {
        if(root == nullptr)
            return false;
        
        if(root->data == data) 
            return true;

        else if (data < root->data) {
            return hasData(data, root->left);
        }
        else {
            return hasData(data, root->right);
        }
    }

    public:
    bool hasData(int data)
    {
        return hasData(data, root);
    }

    public:
    void printTree() {
        return printTree(root);
    }
    private:
    void printTree(BinaryNode<int>* root) {
        if(root == NULL) return;
        cout<< root->data <<":";
        if(root->left != NULL) cout<< "L" << root->left->data;
        if(root->right!=NULL) cout<< "R" << root->right->data;
        cout<< endl;
        printTree(root->left);
        printTree(root->right);
    }

};


class Info {
    public:
    int min; 
    int max; 
    bool isBst;
    int height;
};