class Solution {
public:
    
    int helper(vector<vector<int>>& triangle, vector<vector<int>>& dp, int i, int j) {
        if(i == triangle.size() || j == triangle[i].size()) return 1e9;
        if(i == triangle.size()-1) return triangle[i][j];
        
        if(dp[i][j] != -1) return dp[i][j];
        
        int bottom = 1e9, right = 1e9;
        bottom = helper(triangle, dp, i+1, j);
        if(j < triangle[i].size()) right = helper(triangle, dp, i+1, j+1);

        return dp[i][j] = triangle[i][j] + min(right, bottom);
    }
    
    int minimumTotal(vector<vector<int>>& triangle) {
        vector<vector<int>> dp(triangle.size(), vector<int>(triangle.size(), -1));
        
        return helper(triangle, dp, 0, 0);
    }
};