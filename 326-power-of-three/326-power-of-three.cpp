class Solution {
public:
    
    bool pow(int n){
        if(n%3 != 0) return false;
        else if(n == 3) return true;
        else return pow(n/3);
    }
    
    bool isPowerOfThree(int n) {
        if(n == 1 || n == 3) return true;
        else if(n == 0) return false;
        return pow(n);
    }
};