#include<iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int data) {
        this->data = data;
        this->next = NULL;
    }
};

void printNode(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

void Sort1(Node* &head) {
    int zeros = 0, ones = 0, twos = 0;

    if (head == NULL) {
        cout << "empty list" << endl;
        return;
    }

    // First pass: Count 0s, 1s, and 2s
    Node* curr = head;
    while (curr != NULL) {
        if (curr->data == 0)
            zeros++;
        else if (curr->data == 1)
            ones++;
        else if (curr->data == 2)
            twos++;
        curr = curr->next;
    }

    // Second pass: Overwrite values
    curr = head;
    while (zeros--) {
        curr->data = 0;
        curr = curr->next;
    }
    while (ones--) {
        curr->data = 1;
        curr = curr->next;
    }
    while (twos--) {
        curr->data = 2;
        curr = curr->next;
    }
}

Node* Sort2(Node* &head)
{
    if (head == NULL) {
        cout << "empty list" << endl;
        return head;
    }

    Node* zeroHead = new Node(-101);
    Node* zeroTail = zeroHead;

    Node* oneHead = new Node(-101);
    Node* oneTail = oneHead;

    Node* twoHead = new Node(-101);
    Node* twoTail = twoHead;

    Node* curr = head;

    while (curr!=NULL)
    {
        if(curr->data == 0)
        {
            //remove the block
            Node* temp = curr;
            curr = curr->next;
            temp->next = NULL;

            //add it to the new LL
            zeroTail -> next = temp;
            zeroTail = temp;
        }

        else if(curr->data == 1)
        {
            //remove the block
            Node* temp = curr;
            curr = curr->next;
            temp->next = NULL;

            //add it to the new LL
            oneTail -> next = temp;
            oneTail = temp;
        }

        else if(curr->data == 2)
        {
            //remove the block
            Node* temp = curr;
            curr = curr->next;
            temp->next = NULL;

            //add it to the new LL
            twoTail -> next = temp;
            twoTail = temp;
        }

    }
            //remove -101 from one and two's LL. Maintain it for 0 incase it becomes empty
            Node* temp = oneHead;
            oneHead = oneHead->next;
            temp->next = NULL;
            delete temp;
    
            Node* temp = twoHead;
            twoHead = twoHead->next;
            temp->next = NULL;
            delete temp;
    
            //merge the LL
            if(oneHead!=NULL)
            {
                zeroTail->next = oneHead;
                if(twoHead!=NULL)
                {
                    oneTail->next = twoHead;
                }
            }
            else
            {
                if(twoHead!=NULL)
                {
                    oneTail->next = twoHead;
                }
            }
    
            //remove the first block of zero LL
            Node* temp = zeroHead;
            zeroHead = zeroHead->next;
            temp->next = NULL;
            delete temp;
            
    return zeroHead;
}
int main() {
    Node* first = new Node(1);
    Node* second = new Node(0);
    Node* third = new Node(2);
    Node* fourth = new Node(2);
    Node* fifth = new Node(0);
    Node* sixth = new Node(1);

    first->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;
    fifth->next = sixth;

    cout << "Before sorting: ";
    printNode(first);

    Node* head = Sort2(first);

    cout << "After sorting: ";
    printNode(head);

    return 0;
}
