#include<iostream>
#include "BinaryNode.h"
#include "BinarySearchTree.h"
#include<queue>
#include<vector>
#include<map>
using namespace std;

void printTree(BinaryNode<int> *root) {
    if(root == NULL) return;
    cout<< root->data <<":";
    if(root->left != NULL) cout<< "L" << root->left->data;
    if(root->right!=NULL) cout<< "R" << root->right->data;
    cout<< endl;
    printTree(root->left);
    printTree(root->right);
}

void printLevelWise(BinaryNode<int>* root) {
    if(root == NULL) return;
    queue<BinaryNode<int>*> pendingNodes;
    pendingNodes.push(root);
    while(pendingNodes.size()!=0) {
        BinaryNode<int>* front = pendingNodes.front();
        pendingNodes.pop();
        cout<< front->data <<":";
        if(front->left != NULL) {
            cout<< "L" << front->left->data;
            pendingNodes.push(front->left);
        }
        if(front->right!=NULL) {
            cout<< "R" << front->right->data;
            pendingNodes.push(front->right);
        }
        cout<< endl;
    }
    
}

BinaryNode<int>* takeInput() {
    int rootdata;
    cout<< "enter data" <<endl;
    cin>> rootdata;
    if(rootdata == -1) {
        return NULL;
    }

    BinaryNode<int>* root = new BinaryNode<int>(rootdata);
    BinaryNode<int>* leftChild = takeInput();
    BinaryNode<int>* rightChild = takeInput();
    root->left = leftChild;
    root->right = rightChild;
    return root;
}

BinaryNode<int>* takeInputLevelWise() {
    int rootData;
    cout<< "Enter root data" << endl;
    cin>> rootData;
    if(rootData == -1) return NULL;

    BinaryNode<int>* root = new BinaryNode<int>(rootData);

    queue<BinaryNode<int>*> pendingNodes;
    pendingNodes.push(root);
    while(pendingNodes.size()!=0) {
        BinaryNode<int>* front = pendingNodes.front();
        pendingNodes.pop();
        cout<< "Enter left child of " << front->data <<endl;
        int leftChildData;
        cin>> leftChildData;
        if(leftChildData != -1) {
            BinaryNode<int>* child = new BinaryNode<int>(leftChildData);
            front->left = child;
            pendingNodes.push(child);
        }

        cout<< "Enter right child of " << front->data <<endl;
        int rightChildData;
        cin>> rightChildData;
        if(rightChildData != -1) {
            BinaryNode<int>* child = new BinaryNode<int>(rightChildData);
            front->right = child;
            pendingNodes.push(child);
        }
    }
    return root;
}

bool isPresent(BinaryNode<int>* root, int x) {
    if(root == NULL) return false;
    if(root->data == -1) return NULL;

    bool ans = false;
    if(root->data == x) {
        ans = true;
    }
    
    return ans || isPresent(root->left, x) || isPresent(root->right,x); 
}

int heightOfTree(BinaryNode<int> *root) {
    if(root == NULL) return 0;
    
    return max(heightOfTree(root->left), heightOfTree(root->right)) + 1;

}

void mirrorPrint(BinaryNode<int> *root) 
{
    if(root == NULL) return;
    BinaryNode<int>* temp;
    mirrorPrint(root->left);
    mirrorPrint(root->right);
    temp = root->left;
    root->left = root->right;
    root->right = temp;    
}

BinaryNode<int>* buildTree(vector<int> inorder, vector<int> preorder, int instart, int inend, int prestart, int preend, map<int, int> mp) {
    if(prestart>preend || instart>inend) return NULL;

    BinaryNode<int>* root  = new BinaryNode<int>(preorder[prestart]);
    int inRoot = inorder[mp[root->data]];
    int numsLeft = inRoot - instart;

    root->left = buildTree(inorder, preorder, instart, inRoot - 1, prestart + 1, prestart + numsLeft, mp );
    root->right = buildTree(inorder, preorder, inRoot + 1, inend, prestart + numsLeft +1 , preend, mp );

    return root;
}

int sumOfNodes(BinaryNode<int>* root) {
    if(root ==NULL) return 0;

    return sumOfNodes(root->left) + sumOfNodes(root->right) + root->data;
}


pair<int, int> minmax(BinaryNode<int>* root) {
    if(root == NULL) {
        pair<int, int> p;
        p.first = 0;
        p.second = 0;
        return p;
    }

    pair<int, int> leftAns = minmax(root->left);
    pair<int, int> rightAns = minmax(root->right);
    int lmin = leftAns.first;
    int lmax = leftAns.second;
    int rmin = rightAns.first;
    int rmax = rightAns.second;

    int minimum = (lmin!=0 && rmin!=0) ? min(root->data, min(lmin, rmin)): root->data;
    int maximum = max(root->data, max(lmax, rmax));

    pair<int, int> p;
    p.first = minimum;
    p.second = maximum;
    return p;
}

int isBalanced(BinaryNode<int>* root) {
    if(root == NULL) return 0;
    
    int lheight = isBalanced(root->left);
    if(lheight == -1) return -1;
    int rheight =  isBalanced(root->right);
    if(rheight == -1) return -1;
    if(abs(lheight - rheight) >1) return -1;
    else return max(lheight, rheight) +1 ;
}


void printlevels(BinaryNode<int>* root) {
    if (root == NULL)
        return;
    queue< BinaryNode<int> *> pendingNodes;
    pendingNodes.push(root);
    pendingNodes.push(NULL);
    while (pendingNodes.size() != 0)
    {
        BinaryNode<int> *front = pendingNodes.front();
        pendingNodes.pop();
        if(front == NULL) {
            cout<< endl;
            if(!pendingNodes.empty())
                pendingNodes.push(NULL);
        }else {
            cout << front->data<<" ";
            if (front->left != NULL)
            {
                // cout << front->left->data;
                pendingNodes.push(front->left);
            }
            if (front->right != NULL)
            {
                // cout << "R" << front->right->data;
                pendingNodes.push(front->right);
            }
        }
        
    }
}


BinaryNode<int>* deleteLeaf(BinaryNode<int>* root) {
    if(root == NULL) return NULL;
    
    if(root->left == NULL && root->right == NULL)
    {
        delete root;
        return NULL;
    }
    root->left = deleteLeaf(root->left);
    root->right = deleteLeaf(root->right);
    return root;
}

void PrintNoSiblings(BinaryNode<int>* root) {
    if(root == NULL) return;

    if(root->left)
    {
        cout<< root->data <<" ";
        PrintNoSiblings(root->right); 
        
    }
    if(root->right)  {
        cout<< root->data <<" ";
        PrintNoSiblings(root->left);
    }
}


void rangeElements(BinaryNode<int>* root, int low, int high)
{
    if(root == NULL) return;
    if(root->data >= low && root->data <= high) {
        rangeElements(root->left, low, high);
        cout<< root->data << " ";
        rangeElements(root->right, low, high);
    }   
    else if(root->data < low ){
        rangeElements(root->right, low, high);
    } 
    else if(root->data > high)
    {
        rangeElements(root->left, low, high);
    }
}

BinaryNode<int>* constructBST(vector<int> &v, int low, int high) {
    if(low > high) return NULL;
    
    int mid = low + (high - low) / 2;
    BinaryNode<int>* node = new BinaryNode<int>(v[mid]);
    int leftLow = low;
    int leftHigh = mid - 1;
    int rightLow = mid + 1;
    int rightHigh = high;

    node->left = constructBST(v, leftLow, leftHigh);
    node->right = constructBST(v, rightLow, rightHigh);
    return node;
}

void preorder(BinaryNode<int>* root)
{
    if(root == NULL) return;

    cout<< root->data << " ";
    preorder(root->left);
    preorder(root->right);
}


pair<LinkedListNode<int>*, LinkedListNode<int>*> helperLL(BinaryNode<int>* root) {
    if(root == NULL)
    {
        pair<LinkedListNode<int>*, LinkedListNode<int>*> op;
        op.first = NULL;
        op.second = NULL;
        return op;
    }

    LinkedListNode<int>* Node = new LinkedListNode<int>(root->data);
    pair<LinkedListNode<int>*,LinkedListNode<int>*> Lnode = helperLL(root->left);
    pair<LinkedListNode<int>*,LinkedListNode<int>*> Rnode = helperLL(root->right);

    if (Lnode.first == nullptr && Rnode.first == nullptr) {
        LinkedListNode<int>* NewNode = new LinkedListNode<int>(root->data);
        return {NewNode, nullptr};
    }
    else if(Lnode.first == NULL) {
        Node->next = Rnode.first;
        pair<LinkedListNode<int>*, LinkedListNode<int>*> op;
        op.first = Node;
        op.second = Rnode.second;
        return op;
    }
    else if(Rnode.first == NULL) {
        Lnode.second = Node;
        pair<LinkedListNode<int>*, LinkedListNode<int>*> op;
        op.first = Lnode.first;
        op.second = Node;
        return op;
    }

    Lnode.second = Node;
    Node->next = Rnode.first;
    pair<LinkedListNode<int>*, LinkedListNode<int>*> op;
    op.first = Lnode.first;
    op.second = Rnode.second;
    return op;
}

LinkedListNode<int>* convertToLL(BinaryNode<int>* root) {
    return helperLL(root).first;
}


vector<int>* getRootToNodePath(BinaryNode<int>* root, int data)
{
    if(root == NULL)
        return NULL;
    
    if(root->data == data)
    {
        vector<int>* output = new vector<int>();
        output->push_back(root->data);
        return output;
    }

    vector<int>* leftOutput = getRootToNodePath(root->left, data);
    if(leftOutput) {
        leftOutput->push_back(root->data);
        return leftOutput;
    }
    vector<int>* rightOutput = getRootToNodePath(root->right, data);
    if(rightOutput) {
        rightOutput->push_back(root->data);
        return rightOutput;
    }
    else {
        return NULL;
    }
}


vector<int>* getRootToNodePathBST(BinaryNode<int>* root, int data)
{
    if(root == NULL)
        return NULL;
    
    if(root->data == data)
    {
        vector<int>* output = new vector<int>();
        output->push_back(root->data);
        return output;
    }
    else if(data < root->data) {
        vector<int>* leftOutput = getRootToNodePathBST(root->left, data);
        if(leftOutput) {
            leftOutput->push_back(root->data);
            return leftOutput;
        }
    }
    else if(data > root->data) {
        vector<int>* rightOutput = getRootToNodePathBST(root->right, data);
        if(rightOutput) {
            rightOutput->push_back(root->data);
            return rightOutput;
        }
    }
    else return NULL;
}


BinaryNode<int>* insertDuplicateNode(BinaryNode<int>* root) {
    if(root==NULL)
        return NULL;

    BinaryNode<int>* left = insertDuplicateNode(root->left);
    BinaryNode<int>* right = insertDuplicateNode(root->right);
    BinaryNode<int>* duplicate = new BinaryNode<int>(root->data);
    root->left = duplicate;
    duplicate->left = left;
    return root;

}

Info LargestBST(BinaryNode<int>* root) {
    if(root == NULL)
    {
        return {0,0,true, 0};
    }
    if((root->left == NULL) && (root->right == NULL))
    {
        return{root->data, root->data, true, 1};
    }
    Info left =  LargestBST(root->left);
    Info right =  LargestBST(root->right);

    Info ret;
    if(left.isBst && right.isBst && (left.min < root->data) && (right.max > root->data)) {
        ret.height = 1 + left.height + right.height;
        ret.min = left.min;
        ret.max = right.max;
        ret.isBst = true;
    }
    else {
        ret.isBst = false;
        ret.height = max(left.height, right.height);
        ret.min = min(left.min, root->data);
        ret.max = max(right.max, root->data);
    }

    return ret;
}

void Inorder(BinaryNode<int>* root, vector<int>& v) {
    if(root == NULL) {
        return;
    }
    Inorder(root->left, v);
    v.push_back(root->data);
    Inorder(root->right, v);
}

void UpdateTree(BinaryNode<int>* root, vector<int>& v) {
    if(root == NULL ||v.empty()) return;

    UpdateTree(root->left, v);
    root->data = v[0];
    v.erase(v.begin());
    UpdateTree(root->right, v);
}   

void ReplaceWithGreaterSum(BinaryNode<int>* root) {
    vector<int> v;
    Inorder(root, v);
    int n = v.size() - 1, sum = 0;
    for(int i=n;i>=0;i--)
    {
        sum = sum + v[i];
        v[i] = sum;
    }
    UpdateTree(root, v);
}


void helperPathSumRootToLeaf(BinaryNode<int>* root, vector<int> &v, int k, int sum) {
    if(root == NULL) {
        return;
    }

    sum = sum + root->data;
    v.push_back(root->data);

    if(!root->left && !root->right) {
        if(sum == k) {
            for(int i: v) {
                cout<< i <<" ";
            }
            cout<< endl;
        }
        v.pop_back();
        return;
    }

    
    helperPathSumRootToLeaf(root->left, v, k, sum);
    helperPathSumRootToLeaf(root->right, v, k, sum);

    v.pop_back();
    return;
}


void pathSumRootToLeaf(BinaryNode<int>* root, int k) {
    int sum = 0;
    vector<int> v;
    
    helperPathSumRootToLeaf(root, v, k, sum);
}

void printNodesDepthK(BinaryNode<int>* root, int k) {
    if(root == NULL || k<0) return;

    if(k == 0) {
        cout<< root->data << endl;
        return;
    }

    printNodesDepthK(root->left, k - 1);
    printNodesDepthK(root->right, k - 1);
}


int printNodesAtDistanceK(BinaryNode<int>* root, int k, int elem) {
    if(root->data == elem) {
        printNodesDepthK(root, k);
        return 0;
    }

    int ld = printNodesAtDistanceK(root->left, k, elem);
    if(ld != -1) {
        if(ld + 1 == k) {
            cout<< root->data <<endl;
            return ld + 1;
        }
        else {
            printNodesDepthK(root->right, k - ld - 2);
        }
    }
    else {
        int rd = printNodesAtDistanceK(root->right, k , elem);
        if(rd != -1) {
            if(rd + 1 == k) {
                cout<< root->data << endl;
                return rd + 1;
            }
            else {
                printNodesDepthK(root->left, k - ld - 2);
            }
        }
        else {
            return -1;
        }
    }
    


}


int main()
{
    /*BinaryNode<int>* root = new BinaryNode<int>(1);
    BinaryNode<int>* node1 = new BinaryNode<int>(2);
    BinaryNode<int>* node2 = new BinaryNode<int>(3);
    root->left = node1;
    root->right = node2; */
    // BinaryNode<int>* root1 = takeInputLevelWise();
    // BinaryNode<int>* root2 = takeInputLevelWise();
    // printTree(root);
    // printLevelWise(root);
    // int x;
    // cin>> x;
    // cout << isPresent(root,x);
    // cout<< heightOfTree(root);
    // mirrorPrint(root);
    // printTree(root);
    // pair<int, int> ans = minmax(root);
    // cout<< ans.first << " " <<ans.second << endl;
    BinaryNode<int>* root = takeInputLevelWise();
    // cout<< isBalanced(root);
    // int low, high;
    // cin>> low >> high;
    // rangeElements(root, low, high);
    // 8 5 10 2 6 -1 -1 -1 -1 -1 7 -1 -1    

    // LinkedListNode<int> *Node = convertToLL(root);
    // while(Node!=NULL) {
    //     cout<< Node->data << " ";
    //     Node = Node->next;
    // }
    BST b;
    // b.insertData(5);
    // b.insertData(6);
    // b.insertData(7);
    // b.insertData(2);
    // b.insertData(3);
    // b.insertData(1);
    // b.insertData(9);

    // b.printTree();
    // b.setRoot(insertDuplicateNode(b.getRoot()));
    // Info ans = LargestBST(b.getRoot());
    // cout<< ans.height << endl;
    // ReplaceWithGreaterSum(b.getRoot());
    // b.printTree();
    b.setRoot(root);
    int k, elem;
    cin>> k >> elem;
    printNodesAtDistanceK(b.getRoot(), k , elem);
    // int k = 13;
    // pathSumRootToLeaf(b.getRoot(),k);
    // b.printTree();
}

