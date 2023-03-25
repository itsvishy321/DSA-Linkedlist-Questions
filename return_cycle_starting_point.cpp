// Given the head of a linked list, 
// return the node where the cycle begins. 
// If there is no cycle, return null.

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

Node* loopStartingNode(Node* head)
{
    // Base case
    if (head == NULL)
        return NULL;

    Node* slow = head;
    Node* fast = head;
    bool flag = false;

    while (slow != NULL && fast != NULL)
    {
        // Taking slow 1 step ahead
        slow = slow->next;

        // Taking fast 2 steps ahead
        fast = fast->next;
        if (fast)
        {
            fast = fast->next;
        }

        // check for Cycle 
        if (slow == fast && fast != NULL)
        {
            flag = true;
            break;
        }
    }

    // if it is a circular LL then finding intersecting point
    if (flag)
    {
        // making slow point to head
        slow = head;

        // moving both the pointers ahead
        // 1 step at a time
        while (slow != fast)
        {
            slow = slow->next;
            fast = fast->next;
        }

        return slow;
    }
    else
    {
        return NULL;
    }
}

int main()
{
    vector<int> A = { 3,2,0,-4 };
    Node* head = NULL;
    Node* tail = NULL;

    // Circular LL testcase

    insertNode(tail, 0, A[0]);

    for (int i = 1; i < A.size(); i++)
    {
        insertNode(tail, A[i - 1], A[i]);
    }

    displayC(tail);

    head = tail->next;

    tail->next = tail->next;

    Node* result = loopStartingNode(head);

    cout << "Loop starts at " << result->data << endl;

    return 0;
}