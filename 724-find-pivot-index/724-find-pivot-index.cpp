class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        vector<int> v1;
        for (int i=0;i<nums.size();i++){
            int element = nums[i];
            v1.push_back(element);
        }
        for(int i=nums.size()-2;i>=0;i--){
            v1[i] = v1[i] + v1[i+1];
        }
        for (int i = 1;i<nums.size();i++){
            nums[i] = nums[i] + nums[i-1];
        }
        for(int i=0;i<nums.size();i++){
            if(nums[i] == v1[i]) return i;
        }
        return -1;
    }
};