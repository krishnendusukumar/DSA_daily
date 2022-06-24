class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int,int> m,n;
        for(int i = 0;i < nums.size();i++){
            m[nums[i]] = 0;
        }
        for(int i = 0 ;i < nums.size();i++){
            if(m[nums[i]]>0 || n[nums[i]]>0){
                cout<<i-m[nums[i]]<<" ";
               if(i- m[nums[i]] <= k) 
                    return true;
                else m[nums[i]] = i;
            }
            else 
               { cout<<m[nums[i]]<<" ";
                n[nums[i]]++;
                m[nums[i]] = i;}
        }
        return false;
    }
};