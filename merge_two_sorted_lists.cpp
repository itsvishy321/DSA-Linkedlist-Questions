/*
You are given the heads of two sorted linked lists list1 and list2.
Merge the two lists in a one sorted list.
The list should be made by splicing together the nodes of the first two lists.
Return the head of the merged linked list.
*/

#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(): val(0), next(nullptr) {}
    ListNode(int x): val(x), next(nullptr) {}
    ListNode(int x, ListNode* next): val(x), next(next) {}
};

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        // Base cases
        if (list1 == NULL && list2 == NULL)
            return NULL;
        else if (list1 == NULL)
            return list2;
        else if (list2 == NULL)
            return list1;


        ListNode* curr1 = list1;
        ListNode* curr2 = list2;

        // updating head of list1 while value of current node of list2
        // is less or equal to the head of list1
        while (curr1 && curr2 && curr2->val <= curr1->val)
        {
            ListNode* temp = new ListNode(curr2->val);
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

            else if (curr1->val <= curr2->val && curr1->next->val >= curr2->val)
            {
                ListNode* temp = new ListNode(curr2->val);
                temp->next = curr1->next;
                curr1->next = temp;
                curr2 = curr2->next;
            }
            curr1 = curr1->next;
        }

        // return the updated list1
        return list1;
    }
};

int main()
{
    vector<int> A = { 1,2,4 };
    vector<int> B = { 1,3,4 };

    ListNode* list1 = new ListNode(A[0]);
    ListNode* list2 = new ListNode(B[0]);
    ListNode* temp1 = list1;
    ListNode* temp2 = list2;

    // Making list1
    for (int i = 1; i < A.size(); i++)
    {
        ListNode* temp = new ListNode(A[i]);
        temp1->next = temp;
        temp1 = temp;
    }

    // Making list2
    for (int i = 1; i < B.size(); i++)
    {
        ListNode* temp = new ListNode(B[i]);
        temp2->next = temp;
        temp2 = temp;
    }
    ListNode* curr = list1;
    while (curr)
    {
        cout << curr->val << "  ";
        curr = curr->next;
    }
    cout << endl << endl;

    curr = list2;
    while (curr)
    {
        cout << curr->val << "  ";
        curr = curr->next;
    }
    cout << endl << endl;

    // calling the merge function via object
    Solution object;
    ListNode* mergedList = object.mergeTwoLists(list1, list2);

    curr = mergedList;
    while (curr)
    {
        cout << curr->val << "  ";
        curr = curr->next;
    }
    cout << endl << endl;

    return 0;
}