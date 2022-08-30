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
        vector<vector<int>> dp(coins.size(), vector<int>(amount+1, 0));
        for(int i = 0; i <= amount; i++) {
            if(i % coins[0] == 0) dp[0][i] = i / coins[0];
            else dp[0][i] = 1e9;
        }
        for(int i = 1; i < coins.size(); i++) {
            for(int sum = 0; sum <= amount; sum++) {
                int not_take = 0 + dp[i-1][sum];
                int take = INT_MAX;
                if(sum >= coins[i]) take = 1 + dp[i][sum-coins[i]];
                dp[i][sum] = min(take, not_take);
            }
        }
        int ans = dp[coins.size()-1][amount];
        if(ans >= 1e9) return -1;
        return ans;
    }
};