
//Time Complexity : O(n*m)
//Space Complexity : O(1)

//Approach 1 : Logic base

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.size() == 0 ||  matrix[0].size() == 0) return false;
        int n = matrix.size();
        int m = matrix[0].size();
        for(int i = 0; i < n; i++){
                if(matrix[i][m-1] < target)
                    continue;
                for(int k = 0; k < m; k++)
                    if(matrix[i][k] == target)
                        return true;
            
        }
        return false;
    }
};

//Time Complexity : log(n*m)
//Space Complexity : O(1)

//Approach 2 : Taking advantage of the sorted rows we apply binary search on the whole matrix.

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(!matrix.size()) return false;
        int n = matrix.size();
        int m = matrix[0].size();
        int low = 0, high = n*m - 1, mid;
        while(low <= high){
            mid = low + (high - low)/2;
            if(matrix[mid/m][mid%m] == target)
                return true;
            if(matrix[mid/m][mid%m] < target)
                low = mid+1;
            if(matrix[mid/m][mid%m] > target)
                high = mid-1;
        }
        return false;
    }
};
