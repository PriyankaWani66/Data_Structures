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

void printLeftBoundary(Node* root)
{
    //B.C
    if(root == NULL)
    {
        return;
    }
    //if root is a leaf node, then go back
    if(root->left == NULL && root->right == NULL)
    {
        return;
    }

    cout<<root->data<<" ";
    if(root->left)
    {
        printLeftBoundary(root->left);
    }
    else
    {
        //if left is NULL, then go to right
        printLeftBoundary(root->right);
    }

}

void printLeafBoundary(Node* root)
{
    //B.C
    if(root == NULL)
    {
        return;
    }
    //leaf node
    if(root->left == NULL && root->right == NULL)
    {
        cout<<root->data<<" ";
    }
    printLeafBoundary(root->left);
    printLeafBoundary(root->right);
}

void printRightBoundary(Node* root)
{
    //B.C
    if(root == NULL)
    {
        return;
    }
    //leaf node
    if(root->left == NULL && root->right == NULL)
    {
        return;
    }

    if(root->right)
    {
        printRightBoundary(root->right);
    }
    else
    {
        printRightBoundary(root->left);
    }
    //print in the end to get the right boundary in reverse order
    cout<<root->data<<" ";
}
void boundaryTraversal(Node* root)
{
    if(root==NULL)
    {
        return;
    }

    cout<<root->data<<" ";
    //A: print left boundary
    printLeftBoundary(root->left);
    //B: print leaf nodes
    printLeafBoundary(root);
    //C: print right boundary
    printRightBoundary(root->right);
}
int main()
{
    Node* root = NULL;
    root =  buildTree();
    boundaryTraversal(root);
}