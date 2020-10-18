//Time Complexity : O(n)
//Space Complexity : O(1)

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
       // next_permutation(nums.begin(),nums.end());
        int i = nums.size() - 2;
        while (i >= 0 && nums[i + 1] <= nums[i]) {
            i--;
        }
        if (i >= 0) {
            int j = nums.size() - 1;
            while (j >= 0 && nums[j] <= nums[i]) {
                j--;
            }
            swap(nums[i],nums[j]);
        }
        reverse(nums.begin() + i +1,nums.end());
        
    }
};
