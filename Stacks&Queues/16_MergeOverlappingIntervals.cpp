/* Approach 1 : Brute Force
                In this approach, we simply compare one interval with all the other intervals if overlap
		exists. An overlap is said to exist if the interval to be compared with is not 
		non - overlapping i.e apart from these cases p1.end < p2.start or p2.end < p1.start.
		Thus, if overlap case exists, we can update our reference interval to the calcuted merge
		interval and somehow erase the interval to which the reference interval was compared with.

  Time Complexity : O(n*n)
  Space Complexity : O(1)

*/   

/*Approach : 2 Using Stack
               We first sort the intervals in ascending order of their start time. By sorting we are sure
	       that no interval after a particular non - overlapping interval exists in the sorted array 
	       that can be overlapping. Thus, as soon as we encounter a non-overlapping interval simply
	       push into the stack without caring about the remaining intervals as we are sure that as
	       we have sorted the array those intervals are not overlapping.
	       
 Time Complexity : O(n*logn)
 Space Complexity : O(n)
*/

#include <bits/stdc++.h>
using namespace std;

struct Interval{
    int start;
    int end;
};

bool compare(Interval i1, Interval i2){
    return i1.start < i2.start;
}

int main() {
	int t;
	cin>>t;
	while(t--){
	    int n;
	    cin>>n;
	    Interval arr[n];
	    for(int i = 0; i < n ; i++){
	        cin>>arr[i].start;
	        cin>>arr[i].end;
	    }
	    
	    sort(arr, arr+n, compare);
	    
	    stack<Interval>st;
	    st.push(arr[0]);
	    
	    for(int i = 1; i < n; i++){     //If an interval overlaps, we merge the interval and push
		                            //newly updated interval to the stack, if not we simply
					    //push in into the stack.
	        Interval x = st.top();
	        if(arr[i].start <= x.end){
	             st.pop();
	             x.end = max(arr[i].end, x.end);
	             st.push(x);
	        }
	        else
	             st.push(arr[i]);
	    }
	    stack<Interval> ans;         //Since we need to print the intervals in ascending order
	                                //we make use of another stack.
	    while(!st.empty()){
	        ans.push(st.top());
	        st.pop();
	    }
	    while(!ans.empty()){
	        Interval y = ans.top();
	        cout<<y.start<<" "<<y.end<<" ";
	        ans.pop();
	    }
	    cout<<endl;
	}
	return 0;
}

/*Approach : 3 Optimizing above approach

 Time Complexity : O(n*logn)
 Space Complexity : O(1)
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin>>t;
	while(t--){
	    int n;
	    cin>>n;
	    vector<vector<int>> intervals(n , vector<int>(2));   //tackling the same logic but this time 
	                                                        //instead of creating a structure we use
								//vector of vectors(just for some fun and
								//knowledge).
	    for(int i = 0; i < n; i++){
	        for(int j = 0;  j < 2; j++){
	            cin>>intervals[i][j];
	        }
	    }
	    
	    sort(intervals.begin(), intervals.end(),[](vector<int> &a, vector<int> &b ){
	        return a[0] < b[0];
	    });
	    
	    int k = 0;

	    //To optimize space we modify the intervals vector itself and print only k elements of it.

	    for(int i = 1; i < n; i++){
	        if(intervals[k][1] >= intervals[i][0]){
	            intervals[k][1] = max(intervals[k][1], intervals[i][1]);
	            
	        }
	        else{
	            k++;
	            intervals[k] = intervals[i];
	        }
	    }
	    
	    for(int i = 0; i <= k; i++){
	        for(int j = 0;  j < 2; j++){
	            cout<<intervals[i][j]<<" ";
	        }
	    }
	    cout<<endl;
	    
	   
	}
	return 0;
}

