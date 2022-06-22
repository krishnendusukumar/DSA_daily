class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int i = 1, j = nums.size()-1;
        int n  = nums.size();
        vector<int> arr(n,0);
        while(i<n){
            arr[i] = nums[j--];
            i+=2;
        }
        i = 0;
        while(i<n){
            arr[i] = nums[j--];
            i+=2;
        }
        nums = arr;
    }
};