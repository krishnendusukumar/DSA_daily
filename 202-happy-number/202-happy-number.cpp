class Solution {
public:
    
    bool call(int n, unordered_map<int,int> m){
        if(n == 1) return true;
        if(m[n]>1) return false;
        int j = n, sum = 0;
        while(j!=0){
            int x = j%10;
            sum+=x*x;
            j = j/10;
        }
        m[sum]++;
        return call(sum, m);
    }
    bool isHappy(int n) {
    unordered_map<int,int> m;
        m[n]++;
        return call(n, m);
    }
};