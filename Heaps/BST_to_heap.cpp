#include<iostream>
#include<vector>
#include<queue>
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

//A. Inorder traversal of a BST gives sorted values. Write them back to the tree in postorder for max heap and pre order for min heap.
//Time Complexity: O(n): inorder collects n values → O(n), postorder writes back to n nodes → O(n), level-order print → O(n)
//Space Complexity: O(n): for storing n values in the vector, O(h) for recursion stack in postorder, and O(n) for queue in level-order print.// dominated by O(n) array
void inorder(Node* root, vector<int>& arr){
    //B.C
    if(root==NULL)
    {
        return;
    }
    //L
    inorder(root->left, arr);
    //N
    arr.push_back(root->data);
    //R
    inorder(root->right, arr);
}

void bstToMaxHeapPostorder(Node* root, vector<int> &arr, int& i)
{
    //B.C
    if(root == NULL)
    {
        return;
    }
    //L
    bstToMaxHeapPostorder(root->left, arr, i);
    //R
    bstToMaxHeapPostorder(root->right, arr, i);
    //N
    root->data = arr[i++];

}
//Note: You only need Node*& if you plan to reassign the pointer itself (e.g., replacing root with a new node, deleting it, or making it point to another subtree).
//In our heapify, we never change the pointer itself (root), we only change root->data or root->left/right->data. Passing Node* by value is fine
void heapify(Node* root) {
    while(root){
        Node* largest = root;
        if(root->left!=NULL && root->left->data > largest->data){
            largest = root->left;
        }
        if(root->right!=NULL && root->right->data > largest->data){
            largest = root->right;
        }

        if(largest!=root)
        {
            swap(root->data,largest->data);
            root = largest; // move down to the child we swapped with
        }
        else{
            break;
        }
    }
}

//2. Heappify in its place
//T.C: O(n log n) for n nodes, each heapify takes O(log n) and n for each node
//S.C: O(h) i.e O(log n) for recursion stack.
void bstToMaxHeap_InPlace(Node* root){
    if(root == NULL) return;

    bstToMaxHeap_InPlace(root->left);
    bstToMaxHeap_InPlace(root->right);
    heapify(root);
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

int main(){
    Node* root = new Node(8);
    root->left = new Node(4);
    root->right = new Node(12);
    root->left->left = new Node(2);
    root->left->right = new Node(6);
    root->right->left = new Node(10);
    root->right->right = new Node(14);
    
    //arr to store inorder traversal
    // vector<int> arr;
    // inorder(root, arr);
    // int i=0;
    // bstToMaxHeapPostorder(root,arr,i);

    bstToMaxHeap_InPlace(root); //in place conversion

    //printing the max heap
    cout << "Max Heap from BST: "<<endl;;
    levelOrderTraversal(root);
    return 0;
}