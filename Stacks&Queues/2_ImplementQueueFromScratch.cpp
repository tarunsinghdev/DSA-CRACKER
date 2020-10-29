//Note : Queue implementation is basic so I'm implementing CIRCULAR QUEUE here.

#include<bits/stdc++.h>
#define size 5 
using namespace std;

int myqueue[size];
int front = -1, rear = -1;

void enqueue(int elt){
        if((rear+1)%size == front){
		cout<<"Queue full, Can't push"<<endl;
		return;
	}
	else if(front == -1)
		front = rear = 0;
	else{
		rear = (rear+1)%size;
	}
	myqueue[rear] = elt;
}

void dequeue(){
	if(front == -1 && rear == -1)
		cout<<"No element, Queue empty"<<endl;
	else if(front == rear)
		front = rear = -1;
	else{
		cout<<"Dequeued element :"<<myqueue[front]<<endl;
		front = (front+1)%size;
	}

}

void display(){
	if(front == -1){
		cout<<"Empty Queue"<<endl;
		return;
	}
	for(int i = front; i != rear; i=(i+1)%size){
		cout<<myqueue[i]<<" ";
	}
	cout<<myqueue[rear];
	cout<<endl;
}

int main(){
       cout<<"** MENU **"<<endl;
       cout<<"1. Enqueue"<<endl;
       cout<<"2. Dequeue"<<endl;
       cout<<"3. Display"<<endl;
       cout<<"4. Exit"<<endl;
       int x;
       while(1){
             cout<<"Enter Your Choice"<<endl;
             cin>>x;
             switch(x){
	          case 1 : int elt;
		           cout<<"Enter element to be enqueued"<<endl;
		           cin>>elt;
		           enqueue(elt);
	                   break;
                  case 2 : dequeue();
	                   break;
	          case 3 : display();
	                   break;
		  case 4 : exit(0);	   
	          default : cout<<"Enter correct choice"<<endl;	     
             }
       }
       return 0;
}
       

