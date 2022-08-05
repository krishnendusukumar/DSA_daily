class Solution {
public:
    
    int helper(vector<int>& nums, int target, int sum, vector<unsigned int>& dp) {
        if(sum > target) return 0;
        if(sum == target) return 1;
        
        if(dp[sum] != -1) return dp[sum];
        
        int left = 0;
        for(int i = 0 ; i < nums.size(); i++) {
            left += helper(nums, target, sum+nums[i], dp);
        }
        return dp[sum] = left;
    }
    
    int combinationSum4(vector<int>& nums, int target) {
        vector<unsigned int> dp(target + 1,-1);
        return helper(nums,target, 0, dp);
    }
};