/* Approach : We use two queues here and we try to replicate LIFO operation of stack using queues.

 Time Complexity : push : O(n)
                   pop : O(1)
 Space Complexity : O(n)
*/

/* The method push to push element into the stack */
void QueueStack :: push(int x)
{       
    q2.push(x);
    while(!q1.empty()){
        q2.push(q1.front());
        q1.pop();
    }
    swap(q1, q2);
        // Your Code
}

/*The method pop which return the element poped out of the stack*/
int QueueStack :: pop()
{
        // Your Code  
        if(q1.empty()) return -1;
        int x = q1.front();
        q1.pop();
        return x;
        
}
