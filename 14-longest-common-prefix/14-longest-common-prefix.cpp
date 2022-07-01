class Solution {
public:
    string longestCommonPrefix(vector<string>& s) {
        string x ="";
        sort(s.begin(), s.end());
        string s1 = s[0];
        string s2 = s[s.size()-1];
        for(int i=0;i<s1.size();i++) {
            if(s1[i] == s2[i]) x+=s1[i];
            else return x;
        }
        return x;
    }
};