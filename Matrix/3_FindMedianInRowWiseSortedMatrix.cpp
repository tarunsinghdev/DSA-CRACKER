
//Time Complexity : O(32 * r * log(c))
//Space Complexity : O(1)

class Solution{   
public:
    int median(vector<vector<int>> &matrix, int r, int c){
       //Finding the minimum and maximum element in the matrix
       int mn = INT_MAX, mx = INT_MIN;
       for(int i = 0; i <r; i++){
           mn = min(mn, matrix[i][0]);
           mx = max(mx, matrix[i][c-1]);
       }
       
       int mid = mn + (mx-mn)/2;
       
       int required = (r*c+1)/2;     //As to the left of the median there are n/2 elements present
    while (mn < mx)
    {
        int mid = mn + (mx - mn) / 2;
        int place = 0;
 
        // Find count of elements smaller than mid
        for (int i = 0; i < r; ++i)
            place += upper_bound(matrix[i].begin(), matrix[i].begin()+c, mid) - matrix[i].begin();
        if (place < required)
            mn = mid + 1;
        else
            mx = mid;
    }
    return mn;
        
    }
};
