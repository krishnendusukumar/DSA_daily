class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        int count = 1;
        int max = INT_MIN;
        for(int i=0;i<nums.size()-1;i++) {
            cout<<max;
            if(nums[i] <= nums[i+1]){
                max = nums[i];
            }
            else{
                if(nums[i+1] < max) nums[i+1] = nums[i];
                count--;
            }
        }
        if(count < 0) return false;
        else return true;
    }
};
    
    