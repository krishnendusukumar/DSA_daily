class Solution {
public:
    
    int helper(vector<int>& coins, vector<vector<int>>& dp, int amount, int i) {
        
        if(i == 0) {
            if(amount % coins[i] == 0) return amount / coins[i];
            return 1e9;
        } 
        if(dp[i][amount] != -1) return dp[i][amount];
        
        int not_take = 0 + helper(coins, dp, amount, i-1);
        int take = 1e9;
        if(amount >= coins[i]) take = 1 + helper(coins, dp, amount - coins[i], i);
        return dp[i][amount] = min(take, not_take);
    }
    
    int coinChange(vector<int>& coins, int amount) {
        vector<vector<int>> dp(coins.size(), vector<int>(amount+1, -1));
        int ans = helper(coins, dp, amount, coins.size()-1);
        if(ans == 1e9) return -1;
        else return ans;
    }
};