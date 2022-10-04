#include<iostream>
#include<string.h>
#include<bits/stdc++.h>

using namespace std;
stack<int> s;

void middle(int size){
    int count=0;
    while(count!=size/2){
        s.pop();
        count+=1;
    }
    cout<<"Middle element of Stack is: "<<s.top();
}

int main(){
    int n,i;
    printf("Enter no. of elements: ");
    cin>>n;
    cout<<"Enter atack elements: ";
    for(i=0;i<n;i++){
        int x;
        cin>>x;
        s.push(x);
    }

    middle(n);

    return 0;
}