class Solution {
public:
    
    int helper(vector<vector<int>>& grid, vector<vector<vector<int>>>& dp, int i, int j1, int j2) {
        if(j1 > grid[i].size()-1 ||  j1 < 0 || j2 > grid[i].size()-1 || j2 < 0) return -1e9;
        else if(i == grid.size()-1) {
            if(j1 == j2) return grid[i][j1];
            else return grid[i][j1] + grid[i][j2];
        }
        else if(dp[i][j1][j2] != -1) return dp[i][j1][j2];
        int maxi = -1e9;
        for(int k1 = -1; k1 <= 1; k1++) {
            for(int k2 = -1; k2 <= 1; k2++) {
                int value = 0;
                if(j1 == j2) value = grid[i][j1];
                else value = grid[i][j1] + grid[i][j2];
                value += helper(grid, dp, i+1, j1+k1, j2+k2);
                maxi = max(maxi, value);
            }
        }
        return dp[i][j1][j2] = maxi; 
    }
    
    int cherryPickup(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(m,-1)));
        return helper(grid, dp, 0, 0, grid[0].size()-1);
    }
};