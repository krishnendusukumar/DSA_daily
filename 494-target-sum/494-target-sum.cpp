class Solution {
public:

//         auto it = m.find({idx,target});
//         if(it != m.end()){
//             return it->second;
//         }
        
//         m[{idx,target}] = findPairs(nums,idx-1,target + nums[idx],m) + findPairs(nums,idx-1,target - nums[idx],m);
//         return m[{idx,target}];
    

    int helper(vector<int> nums, map<pair<int,int>, int>& m, int target, int sum, int i) {
        if(i < 0) {
            if(target == sum) return 1;
            else return 0;
        }
        auto it = m.find({i, sum});
        if(it != m.end()) return m[{i, sum}];
        int plus = helper(nums, m, target, sum +nums[i], i-1);
        int minus = helper(nums, m, target, sum-nums[i], i-1);
        return m[{i,sum}] = plus + minus;
    }
    
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        long long sum = 0;
        for(auto it: nums) sum += it;
        map<pair<int,int>, int> m;
        return helper(nums, m, target,0, n-1);
        
    }
};