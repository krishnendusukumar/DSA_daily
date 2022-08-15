#include<bits/stdc++.h>

class Solution {
public:
    
    int helper(vector<int>&arr, int k, int i,  vector<vector<int>>& dp) {
    if(i < 0 || k < 0) return false;
    if(i == 0) return arr[i] == k;
    if(k == 0) return true;
    if(dp[i][k] != -1) return dp[i][k];
    if(helper(arr, k-arr[i],i-1, dp) || helper(arr, k, i-1, dp)) return dp[i][k] = 1;
    else return dp[i][k] = 0;
}
    
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for (auto i: nums) sum+= i;
        vector<vector<int>> dp(200+1, vector<int>(sum/2+1, -1));
        if(sum % 2 == 0) return helper(nums, sum/2, nums.size()-1, dp);
        else return false;
    }
};