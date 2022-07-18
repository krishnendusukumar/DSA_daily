class Solution {
public:
    
    int helper(int i, int j, vector<vector<int>>& triangle, vector<vector<int>>& dp) {
        if(i == triangle.size()-1) return triangle[i][j];
        else if(dp[i][j] != -1) return dp[i][j];
        int left = 0, right = 0;
        left = triangle[i][j] + helper(i+1, j, triangle, dp);
        right = triangle[i][j] + helper(i+1, j+1, triangle, dp);
        return  dp[i][j] = min(left, right);
    }
    
    int minimumTotal(vector<vector<int>>& triangle) {
        
vector<vector<int>> dp(triangle.size(), vector<int>(triangle.size(), -1));
            return helper(0, 0, triangle, dp);
    }
};