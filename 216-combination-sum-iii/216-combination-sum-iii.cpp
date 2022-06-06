class Solution {
public:
    
    void call(int i, vector<int> & subset, int n, int k, vector<vector<int>>& ans, int target){
        if(target < 0) return;
        if(k == 0 ){
        if(target == 0) ans.push_back(subset);
            return;
        }
        if(i == 10) return;
        if(i <= target) {
            subset.push_back(i);
            call(i+1,subset, n, k-1, ans, target - i);
            subset.pop_back();
        }
        call(i+1, subset, n, k, ans, target);
    }
    
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> subset;
        vector<vector<int>> ans;
        int target = n;
        call(1, subset, n, k, ans, target);
        return ans;
    }
};