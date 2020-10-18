#include<bits/stdc++.h>
using namespace std;

void merge(int arr1[], int arr2[], int n, int m) {
	    // code here
	    int gap = n + m;
	    int i, j;
	   // cout<<"here"<<nextGap(gap)<<endl;
	   gap = nextGap(gap);
	    for(; gap > 0 ; gap = nextGap(gap) ){
	          //Comparing elements in first array arr1[]
	       //   cout<<"Mygap"<<gap<<endl;
	          for(i = 0; i + gap < n; i++){
	              if(arr1[i] > arr1[i+gap])
	                 swap(arr1[i], arr1[i+gap]);
	          }
	          //Comparing elements in both array arr1[] and arr2[]
	          
	          for(j = (gap > n) ? (gap - n) : 0; i < n && j < m; i++, j++ ){
	           //   cout<<"gap = "<<gap<<" "<<i<<"#"
	           //cout<<j<<"*"<<" ";
	              
	              if(arr1[i] > arr2[j])
	                 swap(arr1[i], arr2[j]);
	          }
	          
	          //Comparing elements in second array arr2[]
	          if(j < m){
	              for(j = 0; j + gap < m; j++){
	                  if(arr2[j] > arr2[j + gap])
	                    swap(arr2[j], arr2[j+gap]);
	              }
	          }
	    }
}

int main(){

