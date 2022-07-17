class Solution {
public:
    
    int helper(int i, int j, vector<vector<int>>& grid, vector<vector<int>>& dp) {
        if(i == 0 && j == 0) return grid[i][j];
        if(i < 0 || j < 0) return INT_MAX;
        if(dp[i][j] != -1) return dp[i][j];
        int cost1 = helper(i-1, j, grid, dp);
        int cost2 = helper(i, j-1, grid, dp);
        return dp[i][j] = grid[i][j] + min(cost1, cost2);
    }
    
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> dp(n, vector<int> (m, -1));
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                if(i == 0 && j == 0) dp[i][j] = grid[i][j];
                else {
                    int cost1 = INT_MAX, cost2 = INT_MAX;
                    if(i > 0) cost1 = grid[i][j] + dp[i-1][j];
                    if(j > 0) cost2 = grid[i][j] + dp[i][j-1];
                    dp[i][j] = min(cost1, cost2);
                }
            }
        }
        return dp[n-1][m-1];
    }
};