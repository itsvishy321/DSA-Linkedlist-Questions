
// Given a singly linked list of size N of integers. 
// The task is to check if the given linked list is palindrome or not.

//{ Driver Code Starts
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <stack>
using namespace std;
/* Link list Node */
struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

// } Driver Code Ends

#include <vector>

class Solution {
public:
    //Function to check whether the list is palindrome.
    bool isPalindrome(Node* head)
    {
        //Your code here
        if (head == NULL || head->next == NULL)
            return true;


        vector<int> list;
        Node* curr = head;

        while (curr != NULL)
        {
            list.push_back(curr->data);
            curr = curr->next;
        }

        int i = 0;
        int j = list.size() - 1;
        while (i < j)
        {
            if (list[i] != list[j])
            {
                return false;
            }
            i++;
            j--;
        }
        return true;

    }
};



//{ Driver Code Starts.
/* Driver program to test above function*/
int main()
{
    int T, i, n, l, firstdata;
    cin >> T;
    while (T--)
    {

        struct Node* head = NULL, * tail = NULL;
        cin >> n;
        // taking first data of LL
        cin >> firstdata;
        head = new Node(firstdata);
        tail = head;
        // taking remaining data of LL
        for (i = 1;i < n;i++)
        {
            cin >> l;
            tail->next = new Node(l);
            tail = tail->next;
        }
        Solution obj;
        cout << obj.isPalindrome(head) << endl;
    }
    return 0;
}


// } Driver Code Ends