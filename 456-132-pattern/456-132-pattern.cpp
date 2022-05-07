class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        int n=nums.size();
        int a[n];
        stack<int> s;
        a[0]=nums[0];
        for (int i=1;i<n;i++){
            a[i] = min(a[i-1], nums[i]);
        }
        for(int i=n-1;i>=0;i--){
            while(s.size()>0 && s.top()<=a[i]) s.pop();
            if(s.size()>0 && s.top()<nums[i]) return true;
            s.push(nums[i]);
        }
        return false;
    }
};
