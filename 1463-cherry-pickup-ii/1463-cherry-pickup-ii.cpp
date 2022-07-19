class Solution {
public:
    
    int helper(int i, int j1, int j2, vector<vector<int>>& grid, vector<vector<vector<int>>>& dp) {
        if(j1 < 0 || j1 > grid[i].size()-1 || j2 < 0 || j2 > grid[i].size()-1) return -1e9;
        else if(i == grid.size()-1) {
            if(j1 == j2 ) return grid[i][j1];
            else return grid[i][j1] + grid[i][j2];
        }
        else if(dp[i][j1][j2] != -1) return dp[i][j1][j2];
        int maxi = -1e9;
        for(int k1 = -1; k1 <= 1; k1++) {
            for(int k2 = -1; k2 <= 1; k2++) {
                if(j1 == j2 ) maxi = max(maxi , grid[i][j2] + helper(i+1, j1+k1, j2+k2, grid, dp));
                else maxi = max(maxi , grid[i][j2] + grid[i][j1] + helper(i+1, j1+k1, j2+k2, grid, dp));
            }
        }
        return dp[i][j1][j2] = maxi;
        
    }
    
    int cherryPickup(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(m,-1)));
        return helper(0 , 0 , m-1 , grid, dp);
    }
};