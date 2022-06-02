class Solution {
public:
    
    bool pow(long long n){
        if(n == 4) return true;
        else if(n < 4 || n%4 !=0) return false;
        return pow(n/4);
    }
    
    bool isPowerOfFour(int n) {
        if(n == 1 || n == 4) return true;
        else return pow(n);
    }
};