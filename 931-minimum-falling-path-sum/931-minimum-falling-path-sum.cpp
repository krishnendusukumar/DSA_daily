class Solution {
public:
    
    int helper(vector<vector<int>>& matrix, vector<vector<int>>& dp, int i, int j) {
        if(i == matrix.size()-1) return matrix[i][j];
        if(i > matrix.size()-1 || j > matrix.size()-1 || j < 0) return 1e9;
        if(dp[i][j]!= -1) return dp[i][j];
        
        int left = 1e9, right = 1e9, bottom = 1e9;
        if(j > 0) left = helper(matrix, dp, i+1, j-1);
        if(j < matrix.size()-1) right = helper(matrix, dp, i+1, j+1);
        bottom = helper(matrix, dp, i+1, j);
        return dp[i][j] = matrix[i][j] + min(bottom, min(left, right));
    }
    
    int minFallingPathSum(vector<vector<int>>& matrix) {
        vector<vector<int>> dp(matrix.size(), vector<int>(matrix.size(), -1));
        int maxi = 1e9;
            for(int j = 0 ; j < matrix.size(); j++) {
            maxi = min(maxi, helper(matrix, dp, 0, j));
        }
        return maxi;
        }
};