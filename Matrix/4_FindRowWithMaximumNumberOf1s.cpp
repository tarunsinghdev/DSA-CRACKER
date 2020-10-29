  
//Time Complexity : O(m+n)
//Space Complexity : O(1)

//Approach : We find the position(index) of 1(if any) in the first row. Now keeping in mind that the rows are sorted, we iterate over the next rows and 
//           if we found that in the next row there exists a one to the left of the index previously calculated we update our max_row_index and we 
//           continue for the rest of the rows if we can find a 1 whose position is even left of the previous row's 1. This ultimately boils down the 
//           fact that more left the one exits more will be the number of 1s in that row and that row will be our answer. Be careful with the corner cases.

  int first(vector<int> arr, int i, int j){
        while(i <= j){
             int mid = i + (j-i)/2;
             if(arr[mid] == 1 && (arr[mid-1] == 0 || mid == 0))
                  return mid;
             else if(arr[mid] == 0)
                  i=mid+1;
             else
                 j=mid-1;        //As there is more ones to the left of j.
        }
        return -1;
    }

	int rowWithMax1s(vector<vector<int> > arr, int n, int m) {
	    int max_row_index = -1;
	    int j = first(arr[0], 0 , m-1);
	    if(j == -1)
	        j = m-1;
	    
	    if(j == 0 and arr[0][0] == 1)     //Corner Case : for the case when first row itself is all 1.
	       return 0;

	    for(int i = 1; i < n ; i++){
	       
	        while(j>=0 && arr[i][j]  == 1){
	             j--;
	             max_row_index = i;
	        }
	       
	    }
	    return max_row_index;
	}
