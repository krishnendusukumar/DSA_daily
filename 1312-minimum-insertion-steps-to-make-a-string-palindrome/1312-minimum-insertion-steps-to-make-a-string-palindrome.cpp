class Solution {
public:
    
    int call(string& s, vector<vector<int>>& dp, int start, int end) {
        if(start > end) return 0;
        
        if(dp[start][end] != -1) return dp[start][end];
        int res = 0;
        if(s[start] == s[end]) {
            int curr = 2;
            if(start == end) curr = 1;
            res = max(res,curr + call(s, dp, start+1, end-1));
        }
        else {
            res = max(res, call(s, dp, start+1, end));
            res = max(res, call(s, dp, start, end-1));
            // res = max(res, call(s, dp, start+1, end-1));
        }
        return dp[start][end] = res;
    }
    
    int minInsertions(string s) {
        int n = s.size();
        vector<vector<int>> dp(n+1, vector<int>(n+1, -1));
        int x = call(s, dp, 0, n-1);
        cout<<x;
        return (n-x);
    }
};