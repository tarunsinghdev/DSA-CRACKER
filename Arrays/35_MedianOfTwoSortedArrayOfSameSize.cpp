#include<bits/stdc++.h>
using namespace std;

//Approach 1 : Merge method of merge sort. We observe that since the size of the two arrays are same hence the merged array will always be of even length and
//             our median will be the average of elements at indexes n-1 and n.

//Time Complexity : O(n)
//Space Complexity : O(1)
/*
int main(){
	int n;
	cin>>n;
	vector<int> a1(n);
	for(auto &it : a1) cin>>it;
	vector<int> a2(n);
	for(auto &it : a2) cin>>it;
	int cnt = 0, i = 0, j = 0, m1= -1, m2 = -1;
	while(cnt <= n){
		if(i == n){
			m1 = m2; 
			m2= a2[0];
			break;
		}
		if(j == n){
			m1 = m2; 
			m2 = a1[0];
			break;
		}
		if(a1[i] <= a2[j]){
			m1 = m2;                   //Stores the possible previous median
			m2 = a1[i];
			i++;
		}
		else{
			m1 = m2;                  //Stores the possible previous median
			m2 = a2[j];
			j++;
		}
		cnt++;
	}
	cout<<(m1+m2)/2<<endl;
	return 0;
}*/

//Approach 2 : Tricky solution but efficient.

//Time Complexity : O(logn)
//Space Complexity : O(n)

int findMedian(vector<int> array, int startIndex, int endIndex){
	        int indexDiff = (endIndex - startIndex);
                     if (indexDiff % 2 == 0)  
	        {
	            return array[startIndex + (indexDiff/2)];
	        }
	        else
                {
	            return (array[startIndex + (indexDiff/2)] + array[startIndex + (indexDiff/2) + 1])/2;
	        }
}

int findMedianSortedArrays(vector<int> a, vector<int> b, int startIndexA, int endIndexA, int startIndexB, int endIndexB){
	if(endIndexA- startIndexA == 0 || endIndexB-startIndexB == 0)
		return (a[0] + b[0]) /2;
	
	if(endIndexA-startIndexA == 1 && endIndexB-startIndexB == 1)
		return (max(a[startIndexA],b[startIndexB]) + min(a[endIndexA],b[endIndexB]))/2;
	
	int m1 = findMedian(a, startIndexA, endIndexA);
	int m2 = findMedian(b, startIndexB, endIndexB);

	if(m1 == m2)
		return m2;
	
	//since m1<=median<=m2 narrow down search by eliminating elements
	if(m1<m2){
		if ((endIndexA - startIndexA) % 2 == 0) // we are looking at odd number of elements
                {
                startIndexA = startIndexA + (endIndexA - startIndexA) / 2;
                endIndexB = startIndexB + (endIndexB - startIndexB) / 2;
                }
	}
	 // since m2 <= median <= m1 narrow down search by eliminating elements less than m2 and elements greater than m1
        else // m2 < m1
        {
            if ((endIndexB - startIndexB) % 2 == 0) // we are looking at odd number of elements
            {
                startIndexB = startIndexB + (endIndexB - startIndexB) / 2;
                endIndexA = startIndexA + (endIndexA - startIndexA) / 2;
            }
            else
            {
                startIndexB = startIndexB + (endIndexB - startIndexB) / 2;
                endIndexA = startIndexA + (endIndexA - startIndexA) / 2 + 1;                
            }
   	}
        return findMedianSortedArrays(a, b, startIndexA, endIndexA, startIndexB, endIndexB);
}

		
			
int main(){
	int n;
	cin>>n;
	vector<int> a1(n);
	for(auto &it : a1) cin>>it;
	vector<int> a2(n);
	for(auto &it : a2) cin>>it;
	int ans = findMedianSortedArrays(a1, a2, 0, n-1, 0, n-1);
        cout<<ans<<endl;
	return 0;
}
	



