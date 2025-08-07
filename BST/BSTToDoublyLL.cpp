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

//T.C: O(N) and S.C: O(H) and O(N) for skewed tree
void convertBSTToDoublyLL(Node* root, Node* &head)
{
    //B.C
    if(root==NULL)
    {
        return;
    }

    //convert right subtree first
    convertBSTToDoublyLL(root->right, head);
    //point root->right is equal to head 
    root->right = head;
    //if head is not NULL, then point head to root
    if(head != NULL)
    {
        head->left = root;
    }
    //move head to current root
    head = root;

    //convert left subtree
    convertBSTToDoublyLL(root->left, head);
}

//T.C: O(N) and S.C: O(H) and O(N) for skewed tree
Node* sortedLLToBST(Node* &head, int n)
{
    //B.C
    if(head==NULL || n<=0)
    {
        return NULL;
    }

    //left subtree
    Node* leftSub = sortedLLToBST(head,n/2);

    //create root node
    Node* root = head;

    //assign root to root->left
    root->left = leftSub;

    //move head to next node i.e, mid node
    head = head->right;

    //right subtree
    root->right = sortedLLToBST(head, n-n/2-1);

    return root;
}

void printDoublyLinkedList(Node* head)
{
    Node* temp = head;
    while(temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->right;
    }
    cout << endl;
}

int main()
{
    int inorder[] = {1,2,3,4,5,6,7,8,9};
    int e = 8; // size of the inorder array
    Node* root = buildBSTUsingInorder(inorder, 0, e);
    levelOrder(root);
    Node* head = NULL;
    convertBSTToDoublyLL(root, head);
    // Print the doubly linked list
    printDoublyLinkedList(head);
    cout<<"Doubly LL to BST"<<endl;
    Node* root1 = NULL;
    int n = 9; // size of the doubly linked list
    root1 = sortedLLToBST(head,n);
    levelOrder(root1); // Print the BST formed from the doubly linked list
    return 0;
}