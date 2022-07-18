class Solution {
public:
    
    int helper(int i, int j, vector<vector<int>>& triangle, vector<vector<int>>& dp) {
        if(j >= triangle[0].size() || j < 0 ) return 1e9;
        if(i == 0) return triangle[i][j];
        else if(dp[i][j] != -1) return dp[i][j];
        int left = 1e9, right = 1e9, down = 1e9;
        left =  helper(i-1, j, triangle, dp);
        right = helper(i-1, j+1, triangle, dp);
        down = helper(i-1, j-1, triangle, dp);
        return  dp[i][j] = triangle[i][j] + min(down,min(left, right));
    }
    
    
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));
        int maxc = 1e9;
        for(int i = 0; i < matrix[0].size(); i++) {
            dp[0][i] = matrix[0][i];
        }
        for(int i=1; i < matrix.size(); i++) {
            for(int j = 0; j < matrix[i].size(); j++) {
                int left = 1e9, right = 1e9, down = 1e9;
                left = dp[i-1][j];
                if(j > 0) right = dp[i-1][j-1];
                if(j < matrix[i].size()-1) down = dp[i-1][j+1];
                dp[i][j] = matrix[i][j] + min(left, min(right, down));
            }
        }
        for(int i = 0; i < matrix[n-1].size(); i++) {
            maxc = min(maxc, dp[n-1][i]);
        }
        return maxc;
    }
};