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
        vector<int> dp(triangle.back());
        for(int i=triangle.size()-2;i>=0;i--){
            for(int j=0;j<triangle[i].size();j++){
                    dp[j]=triangle[i][j]+min(dp[j], dp[j+1]);
            }
        }
        return dp[0];
    }
};