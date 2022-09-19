class Solution {
public:

    int helper(string s, string t, vector<vector<int>>& dp, int i, int j) {
        if(i < 0 || j < 0) return 0;
        
        if(dp[i][j] != -1) return dp[i][j];
        if(s[i] == t[j]) return dp[i][j] = 1 + helper(s,t, dp, i-1, j-1);
        return dp[i][j] = max(helper(s,t, dp, i-1, j) , helper(s, t, dp, i, j-1));
    }
    
    
    int minDistance(string s, string t) {
        int n = s.size();
        int m = t.size();
        
        vector<vector<int>> dp(n+1, vector<int>(m+1, -1));
        
        int ans = helper(s, t, dp, n-1, m-1);
        return ((n-ans) + (m-ans));
    }
};