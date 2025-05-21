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

void Sort1(Node* &head)
{
    int zeros = 0;
    int ones = 0;
    int twos = 0;

    if(head == NULL)
    {
        cout<<"empty list"<<endl;
        return;
    }
    if(head -> next == NULL)
    {
        cout<<"a single element"<<endl;
        return;
    }

    Node* curr = head;
    while(curr != NULL)
    {
        if(curr->data == 0)
        {
            zeros++;
            curr = curr->next;
        }
        if(curr->data == 1)
        {
            ones++;
            curr = curr->next;
        }
        if(curr->data == 2)
        {
            twos++;
            curr = curr->next;
        }
    }

    curr = head;
    while(zeros--)
    {
        curr->data = 0;
        curr = curr->next;
    }

    while(ones--)
    {
        curr->data = 1;
        curr = curr->next;
    }

    while(twos--)
    {
        curr->data = 2;
        curr = curr->next;
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

    cout<<"After sorting"<<endl;
    Sort1(first);
    printNode(first);
    cout<<endl;

}