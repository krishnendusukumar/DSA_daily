class Solution {
public:
    
    void call(string s, int i, vector<string> &ans){
        if(i == s.size()) return;
        if(islower(s[i])){
            s[i] = toupper(s[i]);
            ans.push_back(s);
            call(s, i+1, ans);
            s[i] = tolower(s[i]);
            call(s, i+1, ans);
        }
        else if(isupper(s[i])){
            s[i] = tolower(s[i]);
            ans.push_back(s);
            call(s, i+1, ans);
            s[i] = toupper(s[i]);
            call(s, i+1, ans);
        }
        else call(s, i+1, ans);
    }
    
    vector<string> letterCasePermutation(string s) {
        vector<string> ans;
        ans.push_back(s);
        call(s, 0, ans);
        return ans;
    }
};