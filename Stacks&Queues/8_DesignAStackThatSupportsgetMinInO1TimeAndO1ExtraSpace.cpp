/*Approach 1 : This solution uses an auxiliary stack named mindata.
               Now we have two stacks with us, one stack 's'(already given in the template) which will 
	       be our main stack and other 'mindata' which will hold the current minimum value while we
	       push elements to the main stack.
	       First, both the stacks will be empty so we push the first element into both the stacks.
	       Then, we keep pushing the data on our main stack and push elements in the mindata stack only
	       if the element is less or equal to the top of the minstack.
	       While popping we pop from the main stack as usual but we pop from the mindata stack only
	       when element at the top of mindata stack is equal to the top of the main stack which we are
	       currently popping.
	       Thus, we can obtain getMin() in O(1) by accessing the top of our mindata stack.


 Time Complexity : push    : O(1)
                   pop     : O(1)
		   getMin  : O(1)
 Space Complexity : O(n)		    
 
*/
stack<int> mindata;

/*Complete the function(s) below*/
void push(int a)
{    
    s.push(a);
    if(mindata.size() == 0 || a <= mindata.top())
         mindata.push(a);
}

bool isFull(int n)
{
     return s.size() == n ? true : false;
     
}

bool isEmpty()
{
    return s.empty();
}

int pop()
{   int val = s.top(); 
    s.pop();
    if(val == mindata.top())
         mindata.pop();
}

int getMin()
{
    return mindata.top();
}

/* Approach 2 : In this, to be able to achieve O(1) getMin() functionality we do some smart work here.
                So every time we call our getMin() function it should return us the "current" minimum value
		in the stack.
		Every time we push an element into our stack we update our "mn" minimum value variable.
		Now the problem lies in the fact that while popping how can we know the current minimum 
		value in the stack as it may be possible that we have popped out the minimum value we 
		calculated from the stack. Now the value our "mn" minimum variable holds is not our 
		minimum value as it has been pop out from the stack. How can we find the previous minimum
		value or retrieve the previous minimum value from the "mn variable". We apply a simple 
		trick.
		Let's rewind, when we are pushing our elements normally into the stack we at the same time
		are maintaining our "mn" variable with the minimum value i.e as soon as we encounter an
		element which is lesser than current minimum we update our "mn" variable. Here also we 
		update our minimum variable but instead of pushing the minimum value encountered into the
		stack we push a fake value which is even lesser than the minimum value we have got with the
		equation val + (val - min). This equation will make sure that fake value is smaller than
		the minimum value.
		Why is it so? As explained earlier we need to know current minimum value of the stack.
		It may be possible the calculated value has been popped out and to retrieve the
		previous value we find it by the equation 2 * min - val.
Proof for the equations : 
		Suppose you have your current minimum value as v which earlier was mn but now has been 
		changed as we encounter new minimum. Now we this v as v + (v-mn) in the stack as minimum
		value.
		Now if we pop out this fake value we know that since this fake value will we lesser 
		than our minimum value our minimum value must have been updated at this time.
		Now we retrieve our previous minimum value by subtracting 2*current minimum(which is v
		here) - fake value i.e
		2* v - (v + (v-mn)) = mn which is our previous minimum value and we have retrieved 
		it back successfully by the simple trick. 
		If you have come this far make sure to star this repo. and text me on linkedin that
		you have understood.
		
 Time Complexity : push    : O(1)
                   pop     : O(1)
		   getMin  : O(1)

 Space Complexity : O(1)

*/

int mn;

void push(int a)
{   if(s.size() == 0){ 
         s.push(a);
         mn = a;
    }
    else if(a >= mn)
         s.push(a);
    else{
        s.push(a + (a - mn));         //We store fake value in the stack which will be later 
	                              //required in the pop function to retrieve our  previous min value
        mn = a;   //Here we store the original minimum value in 'mn' variable and stores a fake value in the stack making it act as flag.
                   // Note that fake value is even smaller than our original minimum value currently.
    }     
     
}

bool isFull(int n)
{
     return s.size() == n ? true : false;
     
}

bool isEmpty()
{
    return s.empty();
}

int pop()
{   int x = s.top();
    if(x >= mn){
         s.pop();
         return x;
    }
    else{
        s.pop();
        mn = 2*mn - x;
        return mn;
    }
}

int getMin()
{
    return mn;
}
