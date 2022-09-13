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
        vector<int> dp(amount+1, 0), temp(amount+1, 0);
        for(int i = 0 ; i <= amount;i++) {
            dp[i] = (i % coins[0] == 0);
        }
        temp = dp;
        for(int i = 1;i < n; i++) {
            for(int j = 0; j <= amount; j++) {
        int not_take = dp[j];
        int take = 0;
        if(coins[i] <= j) take = temp[j-coins[i]]; 
                temp[j] = take + not_take;
            }
            dp = temp;
        }
        return dp[amount];
    }
};