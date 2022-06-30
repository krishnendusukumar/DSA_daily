class Solution {
public:
    int minMoves(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int x = nums[nums.size()-1] - nums[0];
        int ans = 0;
        for(int i=1;i<nums.size()-1;i++){
            ans+=nums[i]+x-nums[nums.size()-1];
        }
        return ans+x;
    }
};
