#include<bits/stdc++.h>
using namespace std;

int mystack[101];
int top = -1;

void push(){
       if(top == 102)
	       cout<<"Can't push, Overflow!"<<endl;
       else{
	       int elt;
	       cout<<"Enter element to be pushed"<<endl;
	       cin>>elt;
	       mystack[++top] = elt;
       }
}

void pop(){
	if(top == -1)
		cout<<"No element, Can't pop"<<endl;
	else
		cout<<"Popped element :"<<mystack[top--]<<endl;

}

void display(){
	for(int i = 0; i <= top; i++){
		cout<<mystack[i]<<" ";
	}
	cout<<endl;
}

int main(){
       cout<<"** MENU **"<<endl;
       cout<<"1. Push"<<endl;
       cout<<"2. Pop"<<endl;
       cout<<"3. Display"<<endl;
       cout<<"4. Exit"<<endl;
       int x;
       while(1){
             cout<<"Enter Your Choice"<<endl;
             cin>>x;
             switch(x){
	          case 1 : push();
	                   break;
                  case 2 : pop();
	                   break;
	          case 3 : display();
	                   break;
		  case 4 : exit(0);	   
	          default : cout<<"Enter correct choice"<<endl;	     
             }
       }
       return 0;
}
       

