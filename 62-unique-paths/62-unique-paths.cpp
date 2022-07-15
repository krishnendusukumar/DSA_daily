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
        vector<vector<int>> dp(m, vector<int>(n, -1));
        dp[0][0] = 1;
        for(int i = 0; i < m;i++) {
            for(int j = 0;j < n;j++) {
                if(i==0 || j==0) dp[i][j] = 1;
                else
                {dp[i][j] = dp[i-1][j] + dp[i][j-1];}
            }
        }
        return dp[m-1][n-1];
    }
};