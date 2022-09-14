class Solution {
public:
    
    int countPrimes(int n) {
        if(n <= 2) return 0;
        
        vector<bool> seen(n, false);
        int cnt = 0;
        for(int i = 2; i < n; i++) {
            if(seen[i]) continue;
            cnt++;
            for(long j = ((long)i*i); j < n; j+=i) seen[j] = true;
        }
        return cnt;
    }
};