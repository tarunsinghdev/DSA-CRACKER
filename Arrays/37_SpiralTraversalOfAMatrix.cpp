#include <bits/stdc++.h>
using namespace std;

//Run this code on your local system. This code is 100% correct. GFG have some issue in this question with the test cases.

//Time Complexity : O(m*n)
//Space Complexity : O(n)

int main() {
	int t;
	cin>>t;
	while(t--){
	    int m, n;
	    cin>>m>>n;
	    int mat[m][n] ={0};

	    for(int i = 0; i < m; i++){
	        for(int j  = 0; j < n; j++){
	            cin>>mat[i][j];
	        }
	    }
	    int top = 0, bottom = m-1, right = n-1, left = 0;
	    while(1){
		    if(left > right)
			    break;

		    for(int i = left; i <= right; i++)    //Top row
			    cout<<mat[top][i]<<" ";
		    top++;

                    if(top > bottom)
			    break;

		    for(int i = top; i <= bottom; i++)    //Right column
			    cout<<mat[i][right]<<" ";
		    right--;

                    if(left > right)
			    break;

		    for(int i = right; i >= left; i--)      //Bottom row
			    cout<<mat[bottom][i]<<" ";
		    bottom--;

                    if(top > bottom)
			    break;

		    for(int i = bottom; i >= top; i--)   //Left column
			    cout<<mat[i][left]<<" ";
		    left++;	   
	    }
	    
	}
	return 0;
}
