#include<iostream>
using namespace std;


class Node{
    public:
    int data;
    Node* left;
    Node* right;

    Node(int data){
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

bool findElement(Node* root, int target)
{
    //B.C
    if(root==NULL)
    {
        return false;
    }

    if(root->data == target)
    {
        return true;
    }

    //left subtree
    if(target < root->data)
    {
        return findElement(root->left, target);
    }
    else
    {
        //right subtree
        return findElement(root->right, target);
    }
}

Node* buildBST(Node* root, int data)
{
    if(root==NULL)
    {
        root = new Node(data);
        return root;
    }

    //insert into left part
    if(root->data > data)
    {
        root->left = buildBST(root->left, data);
    }
    //insert into right part for greater than or equal to
    else
    {
        root->right = buildBST(root->right, data);
    }
    return root;
}

void takeInput(Node* &root)
{
    int data;
    cin>>data;

    while(data!=-1)
    {
        root = buildBST(root,data);
        cin>>data;
    }
}

int main()
{
    Node* root = NULL;
    cout<<"Enter input"<<endl;
    takeInput(root);
    int target;
    cout<<"Enter target"<<endl;
    cin>>target;
    bool found = findElement(root, target);
    cout<<"Element found: "<<found<<endl;
    return 0;
}