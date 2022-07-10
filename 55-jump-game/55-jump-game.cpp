class Solution {
public:
    
    bool helper(int i, vector<int> &nums, vector<int>&dp) {
        if(i == nums.size() - 1) 
           { dp[i] = 1;return true;}
        if(i > nums.size() - 1) dp[i] = 0;
        if(dp[i] != -1) return dp[i];
        int sum = i + nums[i];
        for (int j = i+1;j<=sum;j++) {
            if(helper(j, nums, dp)) return true;
            else dp[i] = 0;
        }
        return false;
    }
    
    bool canJump(vector<int>& nums) {
        vector<int>dp(nums.size(), -1);
      return helper(0, nums, dp);
    }
};




 // 2 3 1 1 4