class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        if(nums.size() == 0 || nums.size() == 1) return nums.size();
       int res = 0, count = 1;
        for(int i = 1; i < nums.size();i++) {
            int prev = nums[i] - nums[i-1];
            if((prev > 0 && res <= 0) || (prev < 0 && res >= 0))
                count++, res = prev;
        }
               return count;
    }
};