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

int lengthOfLL(Node* head)
{
    Node* temp = head;
    int length = 0;
    while(temp != NULL)
    {
        length++;
        temp = temp->next;
    }
    return length;
}
Node* ReverseKNodes(Node* &head,int k)
{
    //if LL is empty
    if(head==NULL)
    {
        cout<<"Empty LL"<<endl;
        return NULL;
    }

    //if len of LL<k
    int len = lengthOfLL(head);
    if(len<k)
    {
        cout<<"Length < k"<<endl;
        return head;
    }

    //if k>length
    int count=0;
    Node* prev = NULL;
    Node* curr = head;
    Node* forward = curr->next;
    while(count<k)
    { 
        forward = curr->next;
        curr->next = prev;
        prev = curr;
        curr =  forward;
        count++;
    }

    if(forward!=NULL)
    {
        head -> next = ReverseKNodes(forward,k);
    }
    return prev;
}

void print(Node *head)
{
    while(head!= NULL)
    {
        cout<<head->data<<" ";
        head = head->next;
    }
}

int main()
{
    Node* first = new Node(10);
    Node* second = new Node(20);
    Node* third = new Node(30);
    Node* fourth = new Node(40);
    Node* fifth = new Node(50);
    Node* sixth = new Node(60);
    first->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;
    fifth->next = sixth;
    sixth->next = NULL;
    print(first);
    cout<<endl;
    first = ReverseKNodes(first,4);
    print(first);
    
}