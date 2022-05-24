class Solution {
public:
    bool check(vector<int>& nums) {
        vector<int> v;
        for (int i = 0; i < nums.size() ; i++){
            v.push_back(nums[i]);
        }
        for (int i = 0; i < nums.size() ; i++){
            v.push_back(nums[i]);
        }
        int count = 0;
        for (int i = 0 ;i < 2*nums.size()-1;i++){
            if(v[i]>v[i+1]) count++;
        }
        if(count>2) return false;
        else return true;
    }
};
