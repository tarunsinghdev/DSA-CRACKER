/* Approach : 1 Using Stacks
 
 Time Complexity : O(n)
 Space Complexity : O(n)

*/

#include <bits/stdc++.h>
using namespace std;

vector<int> nearestSmallerLeftIndex(vector<int> a, int n){
    stack<pair<int, int>> st;
    vector<int> nslIndex;
    int pseudoIndex = -1;
    for(int i = 0; i < n; i++){
        if(st.size() == 0)
            nslIndex.push_back(pseudoIndex);
        else if(st.size() > 0 && st.top().first < a[i])
            nslIndex.push_back(st.top().second);
        else if(st.size() > 0 && st.top().first >= a[i]){
            while(!st.empty() && st.top().first >= a[i])
               st.pop();
            if(st.empty())
               nslIndex.push_back(-1);
            else
               nslIndex.push_back(st.top().second);
        }  
        st.push({a[i], i});
    }
    return nslIndex;
}

vector<int> nearestSmallerRightIndex(vector<int> a, int n){
    stack<pair<int, int>> st;
    vector<int> nsrIndex;
    int pseudoIndex = n;
    for(int i = n-1; i >= 0; i--){
        if(st.size() == 0)
            nsrIndex.push_back(pseudoIndex);
        else if(st.size() > 0 && st.top().first < a[i])
            nsrIndex.push_back(st.top().second);
        else if(st.size() > 0 && st.top().first >= a[i]){
            while(!st.empty() && st.top().first >= a[i])
               st.pop();
            if(st.empty())
               nsrIndex.push_back(pseudoIndex);
            else
               nsrIndex.push_back(st.top().second);
        }  
        st.push({a[i], i});
    }
    reverse(nsrIndex.begin(), nsrIndex.end());
    return nsrIndex;
}

int main() {
	int t;
	cin>>t;
	while(t--){
	    int n;
	    cin>>n;
	    vector<int> a(n), left, right, area(n);
	    for(auto &it : a) cin>>it;
	    
	    left = nearestSmallerLeftIndex(a, n);
	    right = nearestSmallerRightIndex(a, n);
	    
	    vector<int> width(n);
	    for(int i = 0; i < n; i++)
	        width[i] = right[i] - left[i] - 1;
	        
	    for(int i = 0; i < n; i++)
	        area[i] = a[i] * width[i];
	        
	    int maxArea = *max_element(area.begin(), area.end());
	    cout<<maxArea<<endl;
	}
	return 0;
}
