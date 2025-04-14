#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;

    Node()
    {
        this->data = 0;
        this->next = NULL;
    }

    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

void addHeadAtFirst(Node* &head, Node* &tail, int data)
{
    //if it is empty
    if(head==NULL)
    {
        Node* newNode = new Node(data);
        head = newNode;
        tail = newNode;
        return;
    }
    Node* newNode = new Node(data);
    newNode -> next = head;
    head = newNode;
}

void addTail(Node* &head, Node* &tail, int data)
{
    //if it is empty
    if(head==NULL)
    {
        Node* newNode = new Node(data);
        head = newNode;
        tail = newNode;
        return;
    }
    Node* newNode = new Node(data);
    tail -> next = newNode;
    tail = newNode;
}

int calculateLength(Node* head, Node* tail)
{
    int len = 0;
    while(head != NULL)
    {
        len++;
        head = head -> next;
    }
    return len;
}

void addAtPosition(Node* &head, Node* &tail, int data, int position)
{
    //if it is empty
    if(head==NULL)
    {
        Node* newNode = new Node(data);
        head = newNode;
        tail = newNode;
        return;
    }

    //to insert at the firs position
    if(position == 0)
    {
        addHeadAtFirst(head,tail,data);
        return;
    }

    //to insert at the end
    int length = calculateLength(head,tail);
    if(position>=length)
    {
        addTail(head,tail,data);
        return;
    }

    //to insert in between two nodes
    int i=1;
    Node* prev = head;
    while(i<position)
    {
        prev = prev -> next;
        i++;
    }

    Node* curr = prev->next;
    Node* newNode = new Node(data);
    newNode -> next = curr;
    prev -> next = newNode;

}

void deletenode(Node* &head, Node* &tail, int position)
{
    if(head==NULL)
    {
        cout<<"LinkedList is empty, can't delete: "<<endl;
        return;
    }

    //deleting first node
    if(position==0)
    {
        Node* temp = head;
        head = head -> next;
        temp -> next = NULL;
        delete temp;
        return;
    }

    //deleting tail
    int length = calculateLength(head,tail);
    if(position==length-1)
    {
        int i=1;
        Node* prev = head;
        while(i<position)
        {
            prev = prev->next;
            i++;
        }
        prev->next = NULL;
        Node* temp = tail;
        tail = prev;
        delete temp;
        return;
    }

    //deleting middle node
    int i=1;
    Node* prev = head;
    while(i<position)
    {
        prev = prev->next;
        i++;
    }
    Node* curr = prev->next;
    prev->next = curr->next;
    curr->next = NULL;
    delete curr;
    
}
void print(Node* head, Node* tail)
{
    while(head != NULL)
    {
        cout<<head -> data << " ";
        head = head -> next;
    }
}

int main()
{
    Node* head = NULL;
    Node* tail = NULL;
    addHeadAtFirst(head, tail, 10);
    addHeadAtFirst(head, tail, 20);
    addHeadAtFirst(head, tail, 30);
    addHeadAtFirst(head, tail, 40);
    addHeadAtFirst(head, tail, 50);
    addTail(head, tail, 60);
    addAtPosition(head,tail, 70, 3);
    deletenode(head,tail,3);
    print(head, tail);
    return 0;
}