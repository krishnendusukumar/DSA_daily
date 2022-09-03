class Solution {
public:
    void dfs(int num, int n, int k, vector<int>& res) {
        if(n == 0) {
            res.push_back(num);
        }
        else {
            int dig = num % 10;
            if(dig + k <= 9) dfs(num*10 + dig + k, n-1, k, res);
            if(k != 0 && dig >= k) dfs(num*10 + dig - k, n-1, k, res);
        }
    }
    
    
    vector<int> numsSameConsecDiff(int n, int k) {
        vector<int> res;
        for(int i = 1;i <= 9; ++i) {
            dfs(i, n-1, k, res);
        }
        return res;
    }
};