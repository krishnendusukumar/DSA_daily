class Solution {
public:
    int minMoves2(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int sum = 0;
        int med = nums[nums.size()/2];
        for (int i:nums) sum += abs(i-med);
        return sum;
    }
};
