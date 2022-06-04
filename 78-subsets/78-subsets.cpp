class Solution {
public:
    
    void call(vector<int> &nums, int i, vector<int> &subset, vector<vector<int>> &ans ){
        if(i>=nums.size())
        {
            ans.push_back(subset); return;
        }
        subset.push_back(nums[i]);
        call(nums, i+1, subset, ans);
        subset.pop_back();
        call(nums, i+1, subset, ans);
}
    
    
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int> > ans;
        vector<int> subset;
        call(nums, 0, subset, ans);
        return ans;
    }
};
    