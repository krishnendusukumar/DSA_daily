class Solution {
public:
    
    int helper(int i, vector<int>& cost,vector<int>& dp) {
        if(i >= cost.size()) return 0;
        if(dp[i] !=-1) return dp[i];
        int left = helper(i+1, cost, dp);
        int right = helper(i+2, cost, dp);
        return dp[i] = min(left, right)+cost[i];
    }
    
    int minCostClimbingStairs(vector<int>& cost) {
        vector<int> dp(cost.size(), -1);
        return min(helper(0, cost, dp), helper(1, cost, dp));
    }
};
    