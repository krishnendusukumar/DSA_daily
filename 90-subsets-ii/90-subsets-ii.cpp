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
            while(i+1<nums.size() && nums[i] == nums[i+1]) i++;
        call(nums, i+1, subset, ans);
}
    
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> ans;
        vector<int> subset;
        call(nums, 0, subset, ans);
        return ans;
    }
};