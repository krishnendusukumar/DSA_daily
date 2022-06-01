class Solution {
public:
    
    vector<vector<int>> call(vector<int> &nums, int i){
        if(i>=nums.size()) return {{}};
     vector<vector<int>> par = call(nums, i+1);
        vector<vector<int>>ans;
        for (auto j:par) ans.push_back(j);
        for (auto j:par){
            j.push_back(nums[i]);
            ans.push_back(j);
        }
        return ans;
    }
    
    vector<vector<int>> subsets(vector<int>& nums) {
        return call(nums, 0);
    }
};
    