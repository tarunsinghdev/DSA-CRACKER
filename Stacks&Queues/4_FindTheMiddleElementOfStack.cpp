#include <bits/stdc++.h>
using namespace std;

// Function that finds the middle of the stack of size n. Current is current position we’re on
int middle;
void findMiddle(stack<int> &s, int n,int current)
{
// If stack becomes empty or all items already are traversed
if (s.empty() || current == n)
return;

// Remove current item
int x = s.top();
s.pop();

// Call for removing the other items
findMiddle(s, n, current+1);

// Find the middle
if (current == n/2)
middle = x;
}

int main()
{
stack<int> s;

    //push elements into the stack
    s.push(5);
    s.push(6);
    s.push(7);
    s.push(8);
    s.push(9);
    s.push(10);
    s.push(11);
    int current = 0;
    findMiddle(s, s.size(),current);

    // Printing the middle element.
    cout<<middle<<endl;
    return 0;

}
