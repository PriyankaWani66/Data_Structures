#include<iostream>
#include<queue>
using namespace std;

class Node{
    public:
    int data;
    Node* left;
    Node* right;

    Node(int data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};

//take the input as a tree
Node* buildTree(){
    int data;
    cout<<"Enter data"<<endl;
    cin>>data;

    //B.C
    if(data==-1) //-1 is the leaf node
    {
        return NULL;
    }
    //3 steps
    //a: create a node
    Node* root = new Node(data);

    //step 2:
    cout<<"Enter the left part of "<<data<<" node"<<endl;
    root->left = buildTree();

    //step 3:
    cout<<"Enter the right part of "<<data<<" node"<<endl;
    root->right = buildTree();

    return root;

}

void printRightView(Node* root, vector<int>&ans, int level)
{
    //B.C
    if(root==NULL)
    {
        return;
    }

    if(level==ans.size()){
        cout<<root->data<<" ";
        ans.push_back(root->data);
    }

    //right view
    printRightView(root->right, ans, level+1);
    //left view
    printRightView(root->left, ans, level+1);

}

int main()
{
    Node* root = NULL;
    root = buildTree();
    vector<int> ans;
    int level = 0;
    printRightView(root, ans, level);
}