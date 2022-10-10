#include <iostream>

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
    // Function to check if the linked list has a loop.
    bool detectLoop(Node *head)
    {
        if (head == NULL)
            return false;
        else if (head->next == head)
            return true;

        Node *slow = head;
        Node *fast = head->next;

        while (fast != slow)
        {
            if (fast == NULL || fast->next == NULL)
                return false;

            slow = slow->next;
            fast = fast->next->next;
        }

        return true;
    }
};