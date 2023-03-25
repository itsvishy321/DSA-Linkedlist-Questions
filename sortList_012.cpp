// Sort a linked list which contains only 0s , 1s and 2s

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

// FUNCTION FOR SORTING THE LIST
Node* sortList(Node* head)
{
    /*
    // APPROACH 1
    // Time Complexity : O(n)
    // Space Complexity : O(1)

    Node* curr = head;
    vector<int> freqArr(3);

    // Making frequency array for 0 , 1  , 2
    while (curr)
    {
        freqArr[curr->data]++;
        curr = curr->next;
    }

    curr = head;

    for (int i = 0; i < 3; i++)
    {
        int count = 0;
        while (count < freqArr[i])
        {
            curr->data = i;
            curr = curr->next;
            count++;
        }
    }
    return head;
    */

    // APPROACH 2
    // Time Complexity : O(n)
    // Space Complexity : O(n)

    // Making three seoarate linked lists
    Node* zeroHead = new Node(-1);
    Node* zeroTail = zeroHead;
    Node* oneHead = new Node(-1);
    Node* oneTail = oneHead;
    Node* twoHead = new Node(-1);
    Node* twoTail = twoHead;

    Node* curr = head;
    while (curr)
    {
        if (curr->data == 0)
        {
            Node* temp = new Node(0);
            zeroTail->next = temp;
            zeroTail = temp;
        }
        else if (curr->data == 1)
        {
            Node* temp = new Node(1);
            oneTail->next = temp;
            oneTail = temp;
        }
        else
        {
            Node* temp = new Node(2);
            twoTail->next = temp;
            twoTail = temp;
        }
        curr = curr->next;
    }

    // Merging all the three linked lists
    zeroTail->next = oneHead->next;
    if (oneHead->next != NULL)
        oneTail->next = twoHead->next;
    else
        zeroTail->next = twoHead->next;

    return zeroHead->next;
}


int main()
{
    vector<int> A = { 0,2,2,2,2 };
    Node* head = NULL;
    Node* tail = NULL;
    createLL(head, tail, A);
    display(head);

    head = sortList(head);
    display(head);

    return 0;
}
