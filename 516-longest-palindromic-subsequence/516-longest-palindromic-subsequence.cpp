class Solution {
public:
    
    int helper(string s, string t, vector<vector<int>>& dp, int i, int j) {
        if(i < 0 || j < 0) return 0;
        
        if(dp[i][j]!=-1) return dp[i][j];
        if(s[i] == t[j]) return dp[i][j] = 1+helper(s, t, dp, i-1, j-1);
        return dp[i][j] = max(helper(s, t, dp, i-1, j), helper(s, t, dp, i, j-1));
  }
    
    int longestPalindromeSubseq(string s) {
        int n = s.size();
        string t;
        t = s;
        reverse(t.begin(), t.end());
        vector<int> dp(n+1, 0), temp(n+1, 0);
        
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= n; j++) {
                if(s[i-1] ==  t[j-1]) temp[j] = 1+ dp[j-1];
                else {
                    temp[j] = max(dp[j] , temp[j-1]);
                }
            }
            dp = temp;
        }
        return dp[n];
    }
};