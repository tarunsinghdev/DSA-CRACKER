#include<bits/stdc++.h>
using namespace std;

//This code uses concept of quicksort. In this, rather than performing quicksort to the whole array we stop when our pivot becomes the kth smallest element.

int partition(int arr[], int start,int end){
	
	int n = end-start+1;                //This 3 line code of generates a random pivot using rand() function 
	int pivot = rand()%n;
	swap(arr[start+pivot], arr[end]);
	
	pivot = arr[end];
	int pIndex = start;
	for(int i = start; i < end; i++){
		if(arr[i] <= pivot){
			swap(arr[i], arr[pIndex]);
			pIndex++;
		}
	}
	swap(arr[pIndex], arr[end]);
	return pIndex;
}

int kthsmallest(int arr[], int start, int end, int k){
	int pIndex = partition(arr, start, end);
	if(pIndex - start == k-1)
		return arr[pIndex];

	if(pIndex - start > k-1)
		return kthsmallest(arr, start, pIndex-1, k);

	return kthsmallest(arr, pIndex+1, end, k-pIndex+start-1); 
	//while searching the kthsmallest in right half, the kthsmallest element becomes k-((pIndex+1)-start)
}
	

int main(){
	int t;
	cin>>t;
	while(t--){
		int n, k;
		cin>>n;
		int arr[n];
		for(int i = 0; i < n; i++)
			cin>>arr[i];
		cin>>k;	
		cout<<kthsmallest(arr, 0, n-1, k)<<endl;
	}
	return 0;
}

