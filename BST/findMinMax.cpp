#include<iostream>
#include<queue>
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

int findMax(Node* root)
{
    //B.C
    Node* temp = root;
    if (temp==NULL)
    {
        return -1;
    }

    while(temp->right!=NULL)
    {
        temp = temp->right;
    }
    return temp->data;

}

int findMin(Node* root)
{
    //B.C
    Node* temp = root;
    if (temp==NULL)
    {
        return -1;
    }

    while(temp->left!=NULL)
    {
        temp = temp->left;
    }
    return temp->data;

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

int main(){
    Node* root = NULL;
    cout<<"Enter input"<<endl;
    takeInput(root);
    int min = findMin(root);
    int max = findMax(root);
    cout<< "Minimum value in BST: " << min << endl;
    cout<< "Maximum value in BST: " << max << endl;
    return 0;
}