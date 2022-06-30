class Solution {
public:
    int minMoves(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int ans=0;
        for(int i: nums) ans+=i;
        return ans - nums.size()*nums[0];
    }
};