class Solution {
public:
    
    bool pow(int n){
        if(n == 0 || n%2 == 1) return false;
        else if(n == 2) return true;
        else return pow(n/2);
    }
    
    bool isPowerOfTwo(int n) {
        if (n == 1 || n == 2) return true;
        return pow(n);
    }
};