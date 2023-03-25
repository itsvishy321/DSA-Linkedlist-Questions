#include <iostream>
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

void insertAtTail(Node*& head, Node*& tail, int data)
{
    // If DLL is empty
    if (tail == NULL)
    {
        Node* temp = new Node(data);
        tail = temp;
        head = temp;
    }

    else
    {
        Node* temp = new Node(data);
        tail->next = temp;
        tail = temp;
    }


}

void insertAtPosition(Node*& head, Node*& tail, int position, int data)
{
    // Inserting at start
    if (position == 1)
    {
        insertAtHead(head, tail, data);
        return;
    }
    Node* temp = head;
    int cnt = 1;

    while (cnt < position - 1)
    {
        temp = temp->next;
        cnt++;
    }

    // Inserting at last
    if (temp->next == NULL)
    {
        insertAtTail(head, tail, data);
        return;
    }

    // creating a node
    Node* nodeToInsert = new Node(data);
    nodeToInsert->next = temp->next;
    temp->next = nodeToInsert;
}

// ///////////////////// function for reversing a linked list

void reverse(Node*& head, Node* prev, Node* current)
{
    // Base case
    if (current == NULL)
    {
        head = prev;
        return;
    }

    Node* forward = current->next;
    reverse(head, current, forward);
    current->next = prev;
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
    Node* head = NULL;
    Node* tail = NULL;
    insertAtHead(head, tail, 10);
    insertAtHead(head, tail, 6);
    insertAtHead(head, tail, 8);
    insertAtHead(head, tail, 7);
    insertAtHead(head, tail, 9);
    insertAtHead(head, tail, 1);
    insertAtHead(head, tail, 3);

    display(head);

    reverse(head, NULL, head);

    display(head);

    return 0;
}

