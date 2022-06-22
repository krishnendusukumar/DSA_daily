class Solution {
public:
    
    int piv(int l, int r, vector<int>&nums){
        
        int j = l;
        int pivot = nums[r];
        for(int i = l; i < r; i++){
            if(nums[i]>pivot) swap(nums[i], nums[j++]);
        }
        swap(nums[j], nums[r]);
        return j;
    }
    
    int findKthLargest(vector<int>& nums, int k) {
        int start = 0, high = nums.size()-1;
        
        while(start<=high)
        {
        int pivot =  piv(start, high, nums);
        if(pivot > k-1) 
            high = pivot - 1;
        else if(pivot == k-1) 
            return nums[pivot];
        else 
            start = pivot + 1;
        }
        return -1;
    }
};