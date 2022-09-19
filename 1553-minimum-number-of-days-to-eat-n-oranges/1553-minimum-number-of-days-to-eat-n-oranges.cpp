class Solution {
public:
    unordered_map<int, int> m;
    int helper(int n) {
        if(n <= 1) return n;
        
        if(m[n]) return m[n];
        return m[n] = 1 + min(n%2 + helper(n/2), n%3 + helper(n/3));
    }
    
    int minDays(int n) {
        return helper(n);
    }
};