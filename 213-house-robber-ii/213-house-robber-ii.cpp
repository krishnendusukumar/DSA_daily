class Solution {
public:
    
    int helper(vector<int> &nums, int i, vector<int> &dp) {
    if(i == 0) return nums[i];
    if(i < 0) return 0;
    if(dp[i] != -1) return dp[i];
    int pick = nums[i] + helper(nums, i-2, dp);
    int notPick = helper(nums, i-1, dp);
    return dp[i] = max(pick, notPick);
}
    
    int rob(vector<int>& nums) {
        if(nums.size() == 1) return nums[0];
        vector<int> dp1(nums.size()-1, -1),dp2(nums.size()-1, -1), temp1, temp2;
        for(int i=0;i<nums.size();i++) {
            if(i != 0) temp1.push_back(nums[i]);
            if(i != nums.size()-1) temp2.push_back(nums[i]);
        }
        return max(helper(temp1, temp1.size()-1, dp1), helper(temp2, temp2.size()-1, dp2));
    }
};