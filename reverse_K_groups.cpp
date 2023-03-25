// Given the head of a linked list
// reverse the nodes of the list in a group of K
// and return the modified list.

#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node* next;

    // constructor
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

// creation of Linked list
void insertAtHead(Node*& head, Node*& tail, int data)
{

    // If DLL is empty
    if (head == NULL)
    {
        Node* temp = new Node(data);
        head = temp;
        tail = temp;
    }

    else
    {
        // Create new node
        Node* temp = new Node(data);
        temp->next = head;
        head = temp;
    }
}

// function for reversing K nodes
Node* reverseKGroups(Node* head, int k)
{
    // Base case
    if (head == NULL)
        return NULL;

    // STEP 1. reverse first k nodes
    Node* next = NULL;
    Node* curr = head;
    Node* prev = NULL;
    int count = 0;
    while (curr != NULL && count < k)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
        count++;
    }

    // STEP 2. recursive call
    if (next != NULL)
    {
        head->next = reverseKGroups(next, k);
    }

    // STEP 3. return head of reverse linked list
    return prev;
}

void display(Node* head)
{
    cout << "Linked List: ";
    Node* temp = head;
    while (temp != NULL)
    {
        cout << temp->data << "  ";
        temp = temp->next;
    }
    cout << endl << endl;
}

int main()
{
    vector<int> A = { 1,2,3,4,5,6 };
    Node* head = NULL;
    Node* tail = NULL;
    for (int i = 0; i < A.size(); i++)
    {
        insertAtHead(head, tail, A[i]);
    }

    display(head);

    head = reverseKGroups(head, 2);
    display(head);

    return 0;
}