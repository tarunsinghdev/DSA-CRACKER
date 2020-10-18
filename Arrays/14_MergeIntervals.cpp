class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if(intervals.empty()) return intervals;
        sort(intervals.begin(), intervals.end(), [](vector<int> &a, vector<int> &b){
            return a[0] < b[0];
        });
        int index = 0;
        vector<vector<int>> ans;
        ans.push_back(intervals[index]);
        for(int i = 1; i < intervals.size(); i++){
             if(ans[index][1] >= intervals[i][0])
                 ans[index][1] = max(ans[index][1], intervals[i][1]);
            else{
                ans.push_back(intervals[i]);
                index++;
            }
            
        }
        return ans;
    }
};
