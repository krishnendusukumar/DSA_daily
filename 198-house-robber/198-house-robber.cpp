class Solution {
public:
    
    int helper(vector<int> &nums, int i, vector<int>& dp) {
        if(i == 0) return nums[i];
    if(i < 0) return 0;
    if(dp[i] != -1) return dp[i];
    int pick = nums[i] + helper(nums, i-2, dp);
    int notPick = helper(nums, i-1, dp);
    return dp[i] = max(pick, notPick);
    }
    
    int rob(vector<int>& nums) {
        vector<int> dp(nums.size(), -1);
        return helper(nums, nums.size()-1, dp);
    }
};