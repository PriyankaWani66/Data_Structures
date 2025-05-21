//sorted list
#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;

    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

void printNode(Node* head)
{
    Node* temp = head;
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp = temp->next;
    }
}

void removeDuplicates(Node* &head)
{
    //if LL is empty
    if(head == NULL)
    {
        cout<<"LL is empty"<<endl;
        return;
    }

        //if LL has only one node
        if(head->next == NULL)
        {
            cout<<"LL is has a single node"<<endl;
            return;
        }

        Node* curr = head;
        while(curr!=NULL)
        {
            //if data is equal
            if(curr->next!=NULL && curr->data == curr->next->data)
            {
                //delete the node
                Node* temp = curr->next;
                curr->next = curr->next->next;
                temp->next = NULL;
                delete temp;
            }
            else{
                //if data is not equal
                curr = curr->next;
            }
        }
}

int main()
{
    Node* first = new Node(10);
    Node* second = new Node(10);
    Node* third = new Node(30);
    Node* fourth = new Node(30);
    Node* fifth = new Node(40);
    Node* sixth = new Node(40);
    first->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;
    fifth->next = sixth;

    printNode(first);
    cout<<endl;

    removeDuplicates(first);
    cout<<"after removing duplicates"<<endl;
    printNode(first);
}