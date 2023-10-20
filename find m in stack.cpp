
/* C++ Program to implement a stack
that supports findMiddle() and
deleteMiddle in O(1) time */
#include <bits/stdc++.h>
using namespace std;
 
class myStack {
    struct Node {
        int num;
        Node* next;
        Node* prev;
 
        Node(int num) { this->num = num; }
    };
 
    // Members of stack
    Node* head = NULL;
    Node* mid = NULL;
    int size = 0;
 
public:
    void push(int data)
    {
        Node* temp = new Node(data);
        if (size == 0) {
            head = temp;
            mid = temp;
            size++;
            return;
        }
 
        head->next = temp;
        temp->prev = head;
 
        // update the pointers
        head = head->next;
        if (size % 2 == 1) {
            mid = mid->next;
        }
        size++;
    }
 
    int pop()
    {
      int data=-1;
        if (size != 0) {
          data=head->num;
            if (size == 1) {
                head = NULL;
                mid = NULL;
            }
            else {
                head = head->prev;
                head->next = NULL;
                if (size % 2 == 0) {
                    mid = mid->prev;
                }
            }
            size--;
        }
      return data;
    }
 
    int findMiddle()
    {
        if (size == 0) {
            return -1;
        }
        return mid->num;
    }
 
    void deleteMiddle()
    {
        if (size != 0) {
            if (size == 1) {
                head = NULL;
                mid = NULL;
            }
            else if (size == 2) {
                head = head->prev;
                mid = mid->prev;
                head->next = NULL;
            }
            else {
                mid->next->prev = mid->prev;
                mid->prev->next = mid->next;
                if (size % 2 == 0) {
                    mid = mid->prev;
                }
                else {
                    mid = mid->next;
                }
            }
            size--;
        }
    }
};
 
int main()
{
    myStack st;
    st.push(11);
    st.push(22);
    st.push(33);
    st.push(44);
    st.push(55);
    st.push(66);
    st.push(77);
    st.push(88);
    st.push(99);
    cout <<"Popped : "<< st.pop() << endl;
    cout <<"Popped : "<< st.pop() << endl;
    cout <<"Middle Element : "<< st.findMiddle() << endl;
    st.deleteMiddle();
    cout <<"New Middle Element : "<< st.findMiddle() << endl;
    return 0;
}
