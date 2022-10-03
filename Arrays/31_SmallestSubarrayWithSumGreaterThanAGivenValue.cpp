class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int minLen = numeric_limits<int>::max();
        for (int i = 0; i < nums.size() && minLen > 1; i++){
            int sum = 0;
            for (int j = i; j < nums.size(); j++) {
                sum += nums[j];
                if (sum >= s){
                    minLen = min(minLen, j - i + 1);
                    break;  
                }
            }
        }
        
        return minLen == numeric_limits<int>::max() ? 0 : minLen;
    }
};
