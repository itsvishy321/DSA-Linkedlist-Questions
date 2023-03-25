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

// FUNCTION FOR SORTING A LINKED LIST VIA MERGE SORT 

Node* merge(Node* list1, Node* list2)
{
    // Base cases
    if (list1 == NULL && list2 == NULL)
        return NULL;

    else if (list1 == NULL)
        return list2;

    else if (list2 == NULL)
        return list1;

    Node* curr1 = list1;
    Node* curr2 = list2;

    // updating head of list1 while value of current node of list2
    // is less or equal to the head of list1
    while (curr1 && curr2 && curr2->data <= curr1->data)
    {
        Node* temp = new Node(curr2->data);
        temp->next = curr1;
        list1 = temp;
        curr1 = temp;
        curr2 = curr2->next;
    }
    // Inserting the value from node of list2 in list1
    while (curr2 != NULL)
    {
        // If remaining values are greater than the last value of list1
        // then simply join the list1 with current node of list2
        if (curr1->next == NULL)
        {
            curr1->next = curr2;
            break;
        }

        else if (curr1->data <= curr2->data && curr1->next->data >= curr2->data)
        {
            Node* temp = new Node(curr2->data);
            temp->next = curr1->next;
            curr1->next = temp;
            curr2 = curr2->next;
        }
        curr1 = curr1->next;
    }

    // return the updated list1
    return list1;
}

Node* mergeSort(Node* head)
{
    if (head == NULL || head->next == NULL)
        return head;

    Node* slow = head;
    Node* fast = head->next;
    while (fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    Node* left = head;
    Node* right = slow->next;
    slow->next = NULL;

    left = mergeSort(left);    // Sorting left part
    right = mergeSort(right);   // Sorting right part

    // Merging the sorted left and sorted right part
    Node *result = merge(left, right);
    return result;
}



int main()
{
    vector<int> A = { 1,5,2,3,7,4};
    Node* head1 = NULL;
    Node* tail1 = NULL;
    createLL(head1, tail1, A);
    display(head1);

    head1 = mergeSort(head1);
    display(head1);

    return 0;
}