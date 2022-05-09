class Solution {
public:
    
    
    
   void merge(vector<int> &nums, int l, int mid, int r){
        
        int temp[r-l+1];
       int i=l, j=mid+1, k=0;
       while(i<=mid && j<=r){
           if(nums[i] > nums[j]) temp[k++]=nums[j++];
           else temp[k++]=nums[i++];
       }
       
       while(i<=mid) temp[k++]=nums[i++];
       while(j<=r) temp[k++]=nums[j++];
       
       for (i=l;i<=r;i++) nums[i]=temp[i-l];
        
    }
    
    void mergeSort(vector<int> &nums, int l, int r){
        

        if(l<r){
        int mid = (l + r)/2;
        mergeSort(nums, l, mid);
        mergeSort(nums, mid+1, r);
        merge(nums, l, mid, r);
        }
        
        
    }
    
    vector<int> sortArray(vector<int>& nums) {
        
        mergeSort(nums,0, nums.size()-1);
        return nums;
        
    }
};