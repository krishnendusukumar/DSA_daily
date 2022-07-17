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
        dp[0][0] = 1;
        for (int i = 0; i < o.size(); i++) {
            for(int j = 0 ; j < o[0].size(); j++) {
                if(o[i][j] == 1) dp[i][j] = 0;
                else if(i == 0 && j == 0) dp[i][j] = 1;
                else {
                    int up = 0, right = 0;
                    if(i > 0) up = dp[i-1][j];
                    if(j > 0) right = dp[i][j-1];
                    dp[i][j] = up + right;
                }
            }
        }
        return dp[o.size()-1][o[0].size()-1];
    }
};