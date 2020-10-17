#include <iostream>
using namespace std;

//Time Complexity : O(m + n)
//Space Complexity : O(m + n)

//Union of two array

int main() {
    int t;
    cin>>t;
	while(t--){
    	    int n, m;
    	    cin>>n>>m;
    	    int a[n], b[m];
    	    for(int i = 0; i < n; i++)
    	        cin>>a[i];
    	    for(int i = 0; i < m; i++)
    	        cin>>b[i];     
    	    int i = 0, j = 0;
    	    while(i<n && j<m){
    	        if(a[i] < b[j])
                   cout<<a[i++]<<" ";
    	        else if(b[j] < a[i])
		   cout<<b[j++]<<" ";
    	         else{
    	           cout<<b[j++]<<" ";
    	           i++;
		 }
    	    }
    	    while(i<n)
    	       cout<<a[i++]<<" ";
    	    while(j < m)
    	       cout<<b[j++]<<" ";
	    cout<<endl;    
	    }
	return 0;
}

/*  Intersection of Two Arrays.

 Time Complexity  : O(m + n)
 Space Complexity : O(m + n)

int main() {
    int t;
    cin>>t;
	while(t--){
    	    int n, m;
    	    cin>>n>>m;
    	    int a[n], b[m];
    	    for(int i = 0; i < n; i++)
    	        cin>>a[i];
    	    for(int i = 0; i < m; i++)
    	        cin>>b[i];     
    	    int i = 0, j = 0;
    	    while(i<n && j<m){
    	        if(a[i] < b[j])
		    i++;	
    	        else if(b[j] < a[i])
    	           j++;
    	         else{
    	           cout<<b[j++]<<" ";
    	           i++;
		 }
    	    }
    	      
	    }
	return 0;
}
*/


