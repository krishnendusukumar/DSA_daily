class Solution {
public:
    
    int helper(int i, int j, vector<vector<int>>& o, vector<vector<int>>& dp) {
        if(i < 0 || j < 0 || o[i][j] == 1) return 0;
        if(i == 0 && j == 0) return 1;
        if(dp[i][j] != -1) return dp[i][j];
        int left = helper(i-1, j, o, dp);
        int right = helper(i, j-1, o, dp);
        return dp[i][j] = left + right;
        
    } 
    
    int uniquePathsWithObstacles(vector<vector<int>>& o) {
        vector<vector<int>> dp(o.size(), vector<int>(o[0].size(), -1));
        return helper(o.size()-1, o[0].size()-1, o, dp);
    }
};