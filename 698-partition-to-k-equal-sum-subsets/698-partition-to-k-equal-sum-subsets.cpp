class Solution {
public:
    
    bool helper(vector<int>& nums, vector<int>& m, int i, int k, int curr, int x) {
        
        if(i >= nums.size()) return false;
        if(x == 1) return true;
        if(curr == k) return helper(nums, m, 0, k, 0, x-1);
        
      
        
        
       for(int j =i; j < nums.size(); j++){
        if(!m[j] && curr + nums[j] <= k) {
            m[j] = true;
            if(helper(nums, m, j+1, k, curr+ nums[j], x)) return true;
            m[j] = false;
        }
       }
        
        return false;
    }
    
    bool canPartitionKSubsets(vector<int>& nums, int x) {
        int sum = 0;
        for(auto i: nums) sum += i;
        if(sum % x != 0 || nums.size() < x) return false;
        int k = sum/x;
        sort(nums.begin(), nums.end(), greater<int>());
        vector<int> m(nums.size(), false);
            if (!helper(nums, m, 0, k, 0, x)) return false;
        return true;
    }
};