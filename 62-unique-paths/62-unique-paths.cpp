class Solution {
public:
    
    int helper(int i, int j, vector<vector<int>>& dp) {
        if(i == 0 && j == 0) return 1;
        if(i<0 || j<0) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        int left = helper(i, j-1, dp);
        int right = helper(i-1, j, dp);
        return dp[i][j] = left + right;
    }
    
    int uniquePaths(int m, int n) {
        vector<int> v(n, 0), dp(n, 0);
        
        dp[0] = 1;
            for(int i = 0;i < m;i++) {
                for(int j = 0; j < n; j++) {
                    if(i == 0 && j == 0) dp[j] = 1;
                    else {int left = 0;
                    int right = 0;
                    if(i > 0) right = v[j];
                    if(j>0) left = dp[j-1];
                    dp[j] = left + right;}
                }
                v = dp;
            }
        return dp[n-1];
    }
};