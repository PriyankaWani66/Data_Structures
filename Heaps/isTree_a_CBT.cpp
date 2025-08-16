#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* left;
    Node* right;

    Node(int val){
        this->data = val;
        this->left = NULL;
        this->right = NULL;
    }
};

//TC: O(n) => Visits every node exactly once, constant work per node.
int countNodes(Node* root){
    //B.C
    if(root==NULL)
    {
        return 0;
    }

    int total = 1+countNodes(root->left)+countNodes(root->right);
    return total;
}

//T.C: O(n) => Visits every node exactly once, constant work per node.
//S.C: O(h) => O(log n) for a complete binary tree and O(n) for a skewed tree due to recursion stack.
bool isCBT(Node* root, int& index, int total)
{
    //B.C
    if(root==NULL)
    {
        return true;
    }

    if(index>total)  
    {
        return false;
    }

    //left
    int leftIndex = 2*index;
    bool left = isCBT(root->left, leftIndex,total);
    //right
    int rightIndex = 2*index+1;
    bool right = isCBT(root->right, rightIndex,total);

    return left && right;
}

int main(){
    Node* root = new Node(8);
    root->left = new Node(4);
    root->right = new Node(12);
    root->left->left = new Node(2);
    root->left->right = new Node(6);
    //root->right->left = new Node(10);
    root->right->right = new Node(14);
    int total = countNodes(root);
    int index = 1;
    bool ans = isCBT(root, index, total);
    if(ans){
        cout << "The tree is a complete binary tree." << endl;
    }
    else{
        cout << "The tree is not a complete binary tree." << endl;
    }
    return 0;
}