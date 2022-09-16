class Solution {
public:
int helper(vector<vector<int>>& dp, vector<int>& nums, vector<int>& mul, int l, int i) {
    if(i == mul.size()) return 0;
       
       if(dp[l][i] != -1e9) return dp[l][i];
       int left = nums[l]*mul[i] + helper(dp, nums, mul, l+1, i+1);
       int right = nums[nums.size()-1 -(i-l)]*mul[i] + helper(dp, nums, mul, l, i+1);
       return dp[l][i] = max(left, right);
    
}
    
int maximumScore(vector<int>& nums, vector<int>& mults) {
    int m = mults.size();
   vector<vector<int>> dp(m+1, vector<int>(m+1, -1e9));
    return helper(dp, nums, mults, 0, 0);
}
};