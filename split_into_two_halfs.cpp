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

    // destructor
    ~Node()
    {
        int val = this->data;

        if (this->next != NULL)
        {
            delete next;
            next = NULL;
        }
        cout << "Memory freed for " << val << endl;
    }
};

// Inserting on the basis of the value passed 
// if value found : insert after it
// else : Do not insert

void insertNode(Node*& head, int value, int data)
{
    // empty list
    if (head == NULL)
    {
        Node* newNode = new Node(data);
        head = newNode;
        newNode->next = newNode;
    }
    else
    {
        // non empty list
        Node* current = head;
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
void display(Node*& head)
{

    if (head == NULL)
    {
        cout << "Empty list" << endl;
        return;
    }
    Node* temp = head;

    do
    {
        cout << temp->data << "  ";
        temp = temp->next;
    } while (temp != head);


    cout << endl;
}


// FUNCTION TO SPLIT A CIRCULAR LINKED LIST INTO TWO CIRCULAR LL
// FROM MIDDLE
void splitIntoTwo(Node* head, Node*& head1, Node*& head2)
{
    // Base Case
    if (head == NULL || head->next == head)
        return;

    Node* curr = head;
    Node* tail = head;
    while (tail->next != head)
    {
        tail = tail->next;
    }

    int len = 1;
    int middle;

    while (curr->next != head)
    {
        len++;
        curr = curr->next;
    }

    if (len % 2 == 0)
    {
        middle = len / 2 - 1;
    }
    else
    {
        middle = len / 2;
    }

    curr = head;

    // reaching the middle element
    while (middle--)
    {
        curr = curr->next;
    }
    head1 = head;
    head2 = curr->next;
    tail->next = head2;
    curr->next = head1;

}

int main()
{
    Node* head = NULL;
    int A[] = { 1,2,3,4,5,6 };
    insertNode(head, 5, A[0]);
    for (int i = 1; i < 6; i++)
    {
        insertNode(head, A[i - 1], A[i]);
    }

    display(head);

    Node* head1 = NULL;
    Node* head2 = NULL;

    splitIntoTwo(head, head1, head2);

    display(head1);
    display(head2);

    return 0;
}