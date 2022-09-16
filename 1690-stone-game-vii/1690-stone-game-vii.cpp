class Solution {
public:
    int dp[1001][1001];
    
    int helper(vector<int>& stones, int sum, int i, int j) {
        if(i == j) return 0;
        
        if(dp[i][j]) return dp[i][j];
        int left = sum - stones[i] - helper(stones, sum - stones[i], i+1, j);
        int right = sum - stones[j] - helper(stones, sum - stones[j], i, j-1);
        return dp[i][j] = max(left, right);
    }
    
    int stoneGameVII(vector<int>& stones) {
        int sum = 0;
        int n = stones.size();
        for(int i: stones) sum += i;
        return helper(stones, sum, 0, n-1);;
    }
};