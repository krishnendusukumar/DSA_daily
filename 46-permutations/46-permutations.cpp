class Solution {
public:
    void call(vector<int>& arr, int i, vector<vector<int>>& ans){
        if(i == arr.size()) 
            {ans.push_back(arr);return;}
        for (int j = i;j < arr.size();j++){
            swap(arr[i], arr[j]);
            call(arr, i+1, ans);
            swap(arr[i], arr[j]);
        }
        
    }
    
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int> > ans; 
        call(nums, 0, ans);
        return ans;
    }
};