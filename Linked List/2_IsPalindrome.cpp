#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *next;
    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

class Solution
{
    public:
        bool isPalindrome(Node *head)
        {
            Node* slow = head;
            stack<int> s;

            while (slow != NULL) {
                s.push(slow->data);
                slow = slow->next;
            }
        
            while (head != NULL) {
        
                int i = s.top();
                s.pop();

                if (head->data != i) 
                    return false;

                head = head->next;
            }
        
            return true;
        }
};