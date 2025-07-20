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

void preOrderTraversal(Node* root) {
	//NLR
	if(root == NULL)
		return;

	cout << root->data << " ";
	preOrderTraversal(root->left);
	preOrderTraversal(root->right);
}

void inOrderTraversal(Node* root) {
	//LNR
	if(root == NULL)
		return;

	inOrderTraversal(root->left);
	cout << root->data << " ";
	inOrderTraversal(root->right);
}

void postOrderTraversal(Node* root) {
	//LRN
	if(root == NULL)
		return;

	postOrderTraversal(root->left);
	postOrderTraversal(root->right);
	cout << root->data << " ";
}

//to print output in level order
void levelOrderTraversal(Node* root ) {
	queue<Node*> q;
	//initially
	q.push(root);
	q.push(NULL);

	while(!q.empty()) {
		//A
		Node* temp = q.front();
		//B
		q.pop();
		
		if(temp == NULL) {
			cout << endl;
			if(!q.empty()) {
				q.push(NULL);
			}	
		}
		else {
			//C
			cout << temp->data << " ";
			//D
			if(temp -> left) {
				q.push(temp ->left);
			}
			if(temp ->right) {
				q.push(temp->right);
			}
		}
		
		
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
    cout << "Printing the tree" << endl;
	levelOrderTraversal(root);
	cout << endl;

    cout << "Printing Inorder: " << endl;
	inOrderTraversal(root);
	cout << endl;
	cout << "Printing Preorder: " << endl;
	preOrderTraversal(root);
	cout << endl;
	cout << "Printing Postorder: " << endl;
	postOrderTraversal(root);
    return 0;
}