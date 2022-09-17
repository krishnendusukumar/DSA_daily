class Solution {
public:
    
 
    
    long long minimumMoney(vector<vector<int>>& t) {
        
       int mini = 0;
        long long res = 0;
        for(auto it: t) {
            if(it[0] - it[1] > 0) {
                res += it[0] - it[1];
                mini = max(mini, it[1]);
            }
            else mini = max(mini, it[0]);
        }
        return res + mini;
    }
};

