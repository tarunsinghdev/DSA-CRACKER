#include<bits/stdc++.h>
using namespace std;
#define k 3 
#define n 10 
//Approach : In this we take two extra arrays, one for the top indexes of k stacks in top[k] array and
//           other in the next[n] array which stores the next item index for the k stacks

/*Solve it in your notebook and you'll get it.*/

int top[k];    //Global variables automatically gets initialized to zero.
int next_pos[n];
int arr[n]; 
int free_pos;

void push(int data, int sn){
	if(free_pos == -1){
		cout<<"Stack Overflow"<<endl;
		return;
	}
	int i = free_pos;
	free_pos = next_pos[i];

	next_pos[i] = top[sn];
	top[sn] = i;

	arr[i] = data;
}

int pop(int sn){
	if(top[sn] == -1){
		cout<<"Stack Underflow"<<endl;
		return -1;
	}
	int i = top[sn];
	top[sn] = next_pos[i];
	//cout<<free_pos<<endl;
	next_pos[i] = free_pos;
	free_pos = i;
	return arr[i];
}

int main(){
    top[k] = {-1};
    for(int i = 0; i < n; i++)
	    next_pos[i] = i+1;
    next_pos[n-1] = -1;	    

    // Let us put some items in stack number 2 
    push(15, 2); 
    push(45, 2); 
  
    // Let us put some items in stack number 1 
    push(17, 1); 
    push(49, 1); 
    push(39, 1); 
  
    // Let us put some items in stack number 0 
    push(11, 0); 
    push(9, 0); 
    push(7, 0);

    cout << "Popped element from stack 2 is " << pop(2) << endl; 
    cout << "Popped element from stack 1 is " << pop(1) << endl; 
    cout << "Popped element from stack 0 is " << pop(0) << endl;

    return 0;
}
