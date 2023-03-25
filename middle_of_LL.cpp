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

// function to return the middle node of the linked list
// BRUTEFORCE SOLUTION
/*
Node* getMiddle(Node* head)
{
    int len = 0;
    Node* temp = head;

    // calculating length of the LL
    while (temp)
    {
        temp = temp->next;
        len++;
    }

    int middle = len / 2;

    temp = head;

    for (int i = 0; i < middle; i++)
    {
        temp = temp->next;
    }
    return temp;
}
*/

// OPTIMAL SOLUTION
Node* getMiddle(Node* head)
{
    // Base case
    if (head == NULL || head->next == NULL)
        return head;

    Node* slow = head;
    Node* fast = head->next;

    while (fast != NULL)
    {
        // move slow 1 step at a time
        slow = slow->next;

        // move fast 2 steps at a time
        fast = fast->next;
        if (fast != NULL)
            fast = fast->next;
    }
    return slow;
}


int main()
{
    vector<int> A = { 1,2,3,4,5,6,7,8 };
    Node* head = NULL;
    Node* tail = NULL;

    for (int i = 0; i < A.size(); i++)
    {
        insertAtHead(head, tail, A[i]);
    }
    display(head);

    Node* middle = getMiddle(head);
    cout << "Middle = " << middle->data << endl;
    return 0;
}