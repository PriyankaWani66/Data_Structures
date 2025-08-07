#include<iostream>
#include<queue>
using namespace std;

//time complexity: O(n)
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

Node* buildBSTUsingInorder(int inorder[], int s, int e)
{
    //B.C
    if(s>e)
    {
        return NULL;
    }

    //mid
    int mid = (s+e)/2;
    int element = inorder[mid];
    Node* root = new Node(element);

    //left
    root->left = buildBSTUsingInorder(inorder, s, mid-1);
    //right
    root->right = buildBSTUsingInorder(inorder,mid+1,e);

    return root;
}

int main()
{
    int inorder[] = {1,2,3,4,5,6,7,8,9};
    int e = 8; // size of the inorder array
    Node* root = buildBSTUsingInorder(inorder, 0, e);
    levelOrder(root);
    return 0;
}