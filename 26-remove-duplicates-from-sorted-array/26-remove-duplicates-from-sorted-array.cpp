class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        
        int n = nums.size();
        int j=1;
        int i=0;
        int count=1;
        while(i<n && j<n){
            if(nums[i ] == nums[j]) j++;
            else{
                i++;
                swap(nums[i], nums[j]);
                j++;
                count++;
            }
        }
        return count;
        
    }
};