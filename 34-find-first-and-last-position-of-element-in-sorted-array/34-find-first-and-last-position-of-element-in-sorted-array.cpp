class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int low = 0, high = nums.size()-1, lh = -1, rh = -1;
        
        while(low <= high) {
            int mid = (low + high)/2;
            cout<<nums[mid]<<" ";
            if(nums[mid] == target) {
                if(mid - 1 >= 0 && nums[mid] == nums[mid-1]) high = mid-1;
                else {
                    lh = mid; break;
                }
            }
            else if(nums[mid] > target) 
                high = mid-1;
            else low = mid+1;
        }
        low = 0, high = nums.size()-1;
        while(low <= high) {
            int mid = (low + high)/2;
            if(nums[mid] == target) {
                if(mid + 1 < nums.size() && nums[mid] == nums[mid+1]) low = mid+1;
                else {
                    rh = mid; break;
                }
            }
            else if(nums[mid] > target) high = mid-1;
            else low = mid+1;
        }
        return {lh, rh};
    }
};