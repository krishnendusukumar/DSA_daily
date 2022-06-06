class Solution {
public:
    
    void call(int i, int target, vector<vector<int>> &ans, vector<int> &subset, vector<int> &nums){
       if(i == nums.size()){
           if(target == 0)
            ans.push_back(subset);
            return;
        }
        if(target >= nums[i]){
        subset.push_back(nums[i]);
        call(i, target - nums[i], ans,subset, nums);
        subset.pop_back();
        }
        call(i+1, target, ans, subset, nums);
        
    }
    
    
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int> > ans;
        vector<int> subset;
        call(0, target, ans,subset, nums);
        return ans;
        
    }
};