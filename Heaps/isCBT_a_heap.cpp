#include<iostream>
#include<limits.h>
using namespace std;

//to check if a complete binary tree is a heap or not (max heap)
//Time Complexity (T.C): O(n) => Visits every node exactly once, constant work per node.
// Space Complexity (S.C): O(h) => O(log n) for a complete binary tree and O(n) for a skewed tree due to recursion stack.
//It’s one branch at a time, not all nodes.

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

pair<bool,int> isCBT_a_heap(Node* root){
    //B.C
    if(root == NULL){
        pair<bool,int> p = make_pair(true,INT_MIN);
        return p;
    }

    //leaf node
    if(root->left==NULL && root->right==NULL){
        pair<bool,int> p = make_pair(true,root->data);
        return p;
    }

    pair<bool,int> leftAns = isCBT_a_heap(root->left);
    pair<bool,int> rightAns = isCBT_a_heap(root->right);

    if(leftAns.first == true &&
      rightAns.first == true &&
    root->data > leftAns.second &&
    root->data > rightAns.second){
        pair<bool,int> p = make_pair(true, root->data);
        return p;
    }
    else{
        pair<bool,int> p = make_pair(false, root->data);
        return p;
    }

    
}
int main(){
    Node* root = new Node(10);
    root->left = new Node(9);
    root->right = new Node(8);
    root->left->left = new Node(7);
    root->left->right = new Node(12); // violation
    root->right->left = new Node(5);
    root->right->right = new Node(4);

    pair<bool,int> Ans = isCBT_a_heap(root);
    if(Ans.first == true){
        cout<<"The complete binary tree is a max heap"<<endl;
    }
    else{
        cout<<"The complete binary tree is not a max heap"<<endl;
    }
    return 0;
}