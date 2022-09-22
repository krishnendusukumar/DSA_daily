class Solution {
public:
    
    string reverseWords(string s) {
        string res = "", ans = "";
        for(int i = 0 ; i < s.size(); i++) {
            if(s[i] == ' ')
            {
                reverse(ans.begin(), ans.end());
                res += ans;
                ans = "";
                res += " ";
            }
            else ans += s[i];
        }
        if(ans != "") {
            reverse(ans.begin(), ans.end());
            res += ans;
        }
        return res;
    }
};