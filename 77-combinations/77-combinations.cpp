class Solution {
public:
    
    void call(int i, vector<vector<int>> &ans, vector<int> &subset, int n, int k) {
        
        if(i > n)
        {
        if(k == 0)
            ans.push_back(subset);
         return;
        }
        subset.push_back(i);
        call(i+1, ans, subset, n, k - 1);
        subset.pop_back();
        call(i+1, ans, subset, n, k);
    }
    
    
    vector<vector<int>> combine(int n, int k) {
        
        vector<int> subset;
        vector<vector<int>> ans;
        call(1, ans, subset, n, k);
        return ans;
        
    }
};