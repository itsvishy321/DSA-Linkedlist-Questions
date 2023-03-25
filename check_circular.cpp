// Check whether Linked list is circular or not
#include <iostream>
#include <vector>
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

// insert function for circular singly LL
void insertNode(Node*& tail, int value, int data)
{
    // empty list
    if (tail == NULL)
    {
        Node* newNode = new Node(data);
        tail = newNode;
        newNode->next = newNode;
    }
    else
    {
        // non empty list
        Node* current = tail;
        while (current->data != value)
        {
            current = current->next;
        }

        Node* temp = new Node(data);
        temp->next = current->next;
        current->next = temp;
    }
}

// insert function for singly LL
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

// display function for singly LL
void display(Node* head)
{
    Node* temp = head;
    while (temp != NULL)
    {
        cout << temp->data << "  ";
        temp = temp->next;
    }
    cout << endl;
}

// circular linked list traversal
void displayC(Node*& tail)
{
    if (tail == NULL)
    {
        cout << "Empty list" << endl;
        return;
    }
    Node* temp = tail;

    do
    {
        cout << temp->data << "  ";
        temp = temp->next;
    } while (temp != tail);


    cout << endl;
}

bool isCircular(Node* head)
{
    // Basic Approach 
/*

    // base cases
    if (head == NULL)
    {
        return NULL;
    }


    Node* temp = head;
    while ((temp != NULL) && (temp->next != head))
    {
        temp = temp->next;
    }

    if (temp == NULL)
        return false;

    else
        return true;
*/

// FLOYD'S CYCLES FINDING ALGORITHM
    Node* slow = head;
    Node* fast = head;

    while (slow != NULL && fast != NULL)
    {
        slow = slow->next;
        fast = fast->next;
        if (fast)
            fast = fast->next;

        if (slow == fast && fast != NULL)
            return true;
    }

    return false;
}

int main()
{
    vector<int> A = {};
    Node* head = NULL;
    Node* tail = NULL;

    // Singly LL test case

    for (int i = 0; i < A.size(); i++)
    {
        insertAtHead(head, tail, A[i]);
    }
    display(head);

    bool result = isCircular(head);
    if (result)
        cout << "Yes" << endl;

    else
        cout << "NO" << endl;

    // Circular LL testcase

    head = NULL;
    tail = NULL;
    insertNode(tail, 0, A[0]);

    for (int i = 1; i < A.size(); i++)
    {
        insertNode(tail, A[i - 1], A[i]);
    }

    displayC(tail);

    result = isCircular(tail);
    if (result)
        cout << "Yes" << endl;

    else
        cout << "NO" << endl;

    return 0;
}