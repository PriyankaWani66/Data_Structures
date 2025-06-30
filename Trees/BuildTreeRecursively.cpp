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

//print tree or traverse tree using Level order traversal
void levelOrder(Node* root)
{
    queue<Node*> q;
    
    //step 1
    q.push(root);
    q.push(NULL);

    while(!q.empty())
    {
        //A
        Node* temp = q.front();
        //B
        q.pop();

        if(temp==NULL)
        {
            cout<<endl;
            if(!q.empty())
            {
                q.push(NULL);
            }
        }
        else
        {
            cout<<temp->data<<" ";
            if(temp->left)
            {
                q.push(temp->left);
            }
            if(temp->right)
            {
                q.push(temp->right);
            }
        }
        
    }   
    
}

void inorderLevel(Node* root)  //LNR
{
    //B.C
    if(root==NULL)
    {
        return;
    }

    inorderLevel(root->left);
    cout<<root->data<<" ";
    inorderLevel(root->right);
}

void preorderLevel(Node* root)  //NLR
{
    //B.C
    if(root==NULL)
    {
        return;
    }

    cout<<root->data<<" ";
    inorderLevel(root->left);
    inorderLevel(root->right);
}

void postorderLevel(Node* root)  //LRN
{
    //B.C
    if(root==NULL)
    {
        return;
    }

    inorderLevel(root->left);
    inorderLevel(root->right);
    cout<<root->data<<" ";
}
int main()
{
    Node* root = NULL;
    root = buildTree();
    levelOrder(root);
}