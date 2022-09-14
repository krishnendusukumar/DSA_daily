class Solution {
public:
    
    
    int helper(vector<vector<int>>& dp, int i, int n) {
        
        if(i == 1 || n <= 1) {
            return n;
        }
        if(dp[i][n] != -1) return dp[i][n];
        int not_take = helper(dp, i-1, n);
        int take = 1e9;
        if(i*i <= n) take = 1 + helper(dp, i, n-i*i);
        return dp[i][n] = min(take, not_take);
    }
    
    int numSquares(int n) {
        int element = 0;
        for(int i = 1 ; i <= n; i++) {
            if(i*i <= n) element = i;
        }
        vector<vector<int>> dp(element+1, vector<int>(n+1, -1));
        
        return helper(dp, element, n);
    }
};