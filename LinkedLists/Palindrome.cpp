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

Node* reverse(Node* &start)
{
    Node* prev = NULL;
    Node* curr = start;
    Node* forward = curr->next;

    while(curr!=NULL)
    {
        forward = curr->next;
        curr->next = prev;
        prev = curr;
        curr = forward;
    }

    return prev; //start node
}

bool isPalindrome(Node* &first)
{
    //empty LL
    if(first == NULL)
    {
        return false;
    }

    //single LL
    if(first->next == NULL)
    {
        return true;
    }

    //To check palindrome find middle element first =>Floyd Cycle detection
    Node* slow = first;
    Node* fast = first->next; //depends on the requirement

    while(fast!=NULL)
    {
        fast = fast->next;
        if(fast!=NULL)
        {
            fast=fast->next;
            slow=slow->next;
        }
    }

    //after the loop, slow is at the middle element. Now find reverse the LL after the middle element
    Node* reverseStart = reverse(slow->next);
    slow->next = reverseStart; //this is not mandatory

    //compare LL from start to mid and mid+1 to end to check for palindrome
    Node* temp1 = first;
    Node* temp2 = reverseStart;
    while(temp2!=NULL)
    {
        if(temp1->data!=temp2->data)
        {
            return false;
        }
        temp1 = temp1->next;
        temp2 = temp2->next;
    }
    return true;
}

int main()
{
    Node* first = new Node(10);
    Node* second = new Node(20);
    Node* third = new Node(30);
    Node* fourth = new Node(30);
    Node* fifth = new Node(20);
    Node* sixth = new Node(10);
    first->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;
    fifth->next = sixth;
    sixth->next = NULL;
    bool result = isPalindrome(first);
    if(result)
    {
        cout<<"LL is a Palindrome"<<endl;
    }
    else{
        cout<<"LL is not a Palindrome"<<endl;
    }
    
}