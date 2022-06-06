class Solution {
public:
    
    void call(int i, vector<int>& nums, int target, vector<int> & subset, vector<vector<int> > &ans) {
        
        if(target == 0){
            ans.push_back(subset);
            return;
        }
        if(i == nums.size()) return;
        
        if(nums[i] <= target) {
            subset.push_back(nums[i]);
            call(i+1, nums, target-nums[i], subset, ans);
            subset.pop_back();
        }
        while(i+1 < nums.size() && nums[i] == nums[i+1]) i++;
        call(i+1, nums, target, subset, ans);
    }
    
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> subset;
        sort(candidates.begin(), candidates.end());
        call(0 , candidates, target, subset, ans);
        return ans;
    }
};


