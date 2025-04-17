//The Tortoise Algorithm, also known as the slow and fast pointer approach, is commonly used to find the middle node of a singly linked list.

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

Node* middleElement(Node* head)
{
    //fast moves two houses and slow moves one house after that
    Node* slow = head;
    Node* fast = head->next;

    while(fast!=NULL && fast->next!=NULL)
    {
        fast = fast->next;
        if(fast!=NULL)
        {
            fast = fast->next;
            slow = slow->next;
        }
    }
    cout<<slow->data<<endl;
    return slow;
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
    middleElement(first);
}