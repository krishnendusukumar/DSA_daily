class Solution {
    public:
   static bool cmp(pair<int,int>&a, pair<int,int>&b) {
        return  (a.second==b.second) ? a.first>b.first : a.second<b.second;
    }
    vector<int> frequencySort(vector<int>& nums) {
        map<int,int> m;
        for (int i=0;i<nums.size();i++){
            m[nums[i]]++;
        }
        vector<pair<int,int>> val_freq;
        for(auto m : m) 
        {
            val_freq.push_back(m);
        }
        sort(val_freq.begin(),val_freq.end(),cmp);
        int i = 0;
        for(auto it:val_freq){
           while(it.second-->0){
               nums[i++] = it.first;
           }
        }
        return nums;
    }
};