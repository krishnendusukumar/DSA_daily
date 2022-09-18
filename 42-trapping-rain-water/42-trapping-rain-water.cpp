class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        vector<int> pre(n), suff(n);
        pre[0] = height[0];
        suff[n-1] = height[n-1];
        
        for(int i =1; i < n; i++) {
            pre[i] = max(pre[i-1], height[i]);
        }
        for(int i =n-2 ;i >= 0; i--) suff[i] = max(height[i], suff[i+1]);
        int res = 0;
        
        for(int i=0; i < n; i++) {
            res += max(min(pre[i], suff[i]) - height[i], 0);
        }
        return res;
    }
};