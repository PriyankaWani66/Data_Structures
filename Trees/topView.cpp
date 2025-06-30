#include<iostream>
#include<queue>
#include<map>
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


//top view follows level order traversal
void printTopView(Node* root)
{
    //B.C
    if(root==NULL)
    {
        return;
    }

    map<int,int> topNode;
    queue<pair<Node*,int>> q;

    q.push(make_pair(root,0));

    while(!q.empty())
    {
        pair<Node*,int> temp = q.front();
        q.pop();

        Node* frontNode = temp.first;
        int hd = temp.second;

        //if data is not present in the map
        if(topNode.find(hd) == topNode.end())
        {
            topNode[hd] = frontNode->data;
        }

        //left call
        if(frontNode->left)
        {
            q.push(make_pair(frontNode->left,hd-1));
        }
        //right call
        if(frontNode->right)
        {
            q.push(make_pair(frontNode->right,hd+1));
        }

    }

    //print map
    for(auto i: topNode)
    {
        cout<<i.first<<"->"<<i.second<<endl;
    }
}


int main()
{
    Node* root = NULL;
    root = buildTree();
    printTopView(root);
}