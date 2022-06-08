class Solution {
public:
    
    bool check(string s){
        int i = 0, j = s.size()-1;
        while(i <= j){
           if (s[i++] == s[j--]) continue;
            else return false;
        }
        return true;
    }
    
    int removePalindromeSub(string s) {
        if(s.size() <= 2) return 1;
        else if(check(s) == false) return 2;
        else if(check(s) == true) return 1;
        else return true;
    }
};

