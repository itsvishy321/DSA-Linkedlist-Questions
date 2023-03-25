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

void insertAtTail(Node*& head, Node*& tail, int data)
{
    // If SLL is empty
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

void createLL(Node*& head, Node*& tail, vector<int> A)
{
    for (int i = 0; i < A.size(); i++)
    {
        insertAtTail(head, tail, A[i]);
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


// function to delete unsorted Linked list
Node* deleteDuplicates(Node* head) {
    if (head == NULL || head->next == NULL)
        return head;

    map<int, bool> visited;
    Node* curr = head;
    Node* prev = head;

    while (curr)
    {
        if (visited[curr->data] == true)
        {
            prev->next = curr->next;
            curr = curr->next;
        }

        else
        {
            visited[curr->data] = true;
            prev = curr;
            curr = curr->next;
        }
    }
    return head;
}

int main()
{
    // UNSORTED LINKED LIST
    vector<int> A = { 4,4,2 ,5,4,2,2 };
    Node* head = NULL;
    Node* tail = NULL;
    createLL(head, tail, A);
    display(head);

    head = deleteDuplicates(head);
    display(head);

    return 0;
}