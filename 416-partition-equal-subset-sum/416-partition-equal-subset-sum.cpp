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
//     int totalsum=0;
//         int n=arr.size();
//         for(auto &it:arr)totalsum+=it;
//         if(totalsum %2 !=0)return 0;
//         int k=totalsum/2;
//         vector<vector<bool>>dp(n,vector<bool>(k +1,0));
//         for(int i=0;i<n;i++)dp[i][0]=true;
//         if(k>=arr[0])
//             dp[0][arr[0]]=true;
        
//         for(int idx=1;idx<n;idx++){
//             for(int target=1;target<=k;target++){
//                 bool take=0,nottake=0;
//                 nottake= dp[idx-1][target];
//                 if(target>=arr[idx])
//                     take=dp[idx-1][target-arr[idx]];
                
//                  dp[idx][target]=take || nottake;
//             }
//         }
    
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for (auto i: nums) sum+= i;
        if(sum % 2 != 0) return false;
        vector<bool> dp(sum/2+1, 0), temp(sum/2+1, 0);
            dp[0] = temp[0] = true;
        if(sum/2 >= nums[0]) temp[nums[0]] = true;
            for(int i = 1; i < nums.size(); i++) {
                for(int target = 1; target <= sum/2; target++) {
                    bool take = false; 
                    bool not_take = dp[target];
                    if(target >= nums[i]) take = dp[target - nums[i]];
                    temp[target] = take or not_take;
                }
                dp = temp;
            }
        return dp[sum/2];
    }
};