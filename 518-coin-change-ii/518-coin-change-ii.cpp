class Solution {
public:
    
    int helper(int amount, vector<vector<int>>&dp, vector<int> coins, int i) {
        if(i == 0) {
            if(amount%coins[i] == 0) return 1;
            else return 0;
        }
        if(dp[i][amount]!= -1) return dp[i][amount];
        int not_take = helper(amount, dp, coins, i-1);
        int take = 0;
        if(coins[i] <= amount) take = helper(amount- coins[i], dp, coins, i);
        
        return dp[i][amount] = take + not_take;
    }
    
    int change(int amount, vector<int>& coins) {
        int res = 0;
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount+1, -1));
        return helper(amount, dp, coins,n-1);
    }
};