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


void print(Node *head)
{
    while(head!= NULL)
    {
        cout<<head->data<<" ";
        head = head->next;
    }
}

Node* RemoveCycle(Node* &first)
{
    if(first==NULL)
    {
        cout<<"No cycles"<<endl;
        return NULL;
    }

    //to detect cycle => Use Floyd Cycle Detection Loop => if fast==slow => detects loop
    Node* fast = first;
    Node* slow = first;

    while(fast->next!=NULL)
    {
        fast = fast->next;
        if(fast->next!=NULL)
        {
            fast = fast->next;
            slow = slow->next;
        }

        if(slow==fast)  //detects cycle : return true or fast if the program is to detect cycle
        {
            slow = first;  //set it to the head , when slow moves from head towards and fast moves forward and when they meet then that is the starting point of the loop.
            break;
        }
    }

    //prev is one step before fast to be able to remove the cycle
    Node* prev = fast;

    //when slow==fast i.e, starting point of the loop => you can return either slow or fast to get the starting point of the loop
    while(slow!=fast)
    {
        prev = fast;
        slow=slow->next;
        fast=fast->next;
    }

    cout<<"Starting point is: "<<slow->data<<endl;
    //once the cycle is detected, remove the loop by setting the step before the starting point to null
    prev->next = NULL;

    return first;
    
}

int main()
{
    Node* first = new Node(10);
    Node* second = new Node(20);
    Node* third = new Node(30);
    Node* fourth = new Node(40);
    Node* fifth = new Node(50);
    Node* sixth = new Node(60);
    Node* seventh = new Node(70);
    Node* eighth = new Node(80);
    Node* ninth = new Node(90);
    Node* tenth = new Node(100);
    first->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;
    fifth->next = sixth;
    sixth->next = seventh;
    seventh->next = eighth;
    eighth->next = ninth;
    ninth->next = tenth;
    tenth->next = third;
    RemoveCycle(first);
    cout<<endl;
    print(first);
}