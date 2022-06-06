class Solution {
public:
    
    void call(int i, string &s, vector<string> &ans, string &temp, unordered_map<char, string>&m)
    {
        if(i == s.size()) {
            ans.push_back(temp);
            return;
        }
        string str = m[s[i]];
        for (int j = 0;j < str.size();j++){
            temp.push_back(str[j]);
            call(i+1, s, ans, temp, m);
            temp.pop_back();
        }
    }
    
    vector<string> letterCombinations(string digits) {
        if(digits.size() == 0) return {};
        unordered_map<char, string> m;
        vector<string> ans;
        
        m['2'] = "abc";
        m['3'] = "def";
        m['4'] = "ghi";
        m['5'] = "jkl";
        m['6'] = "mno";
        m['7'] = "pqrs";
        m['8'] = "tuv";
        m['9'] = "wxyz";
        
        string temp;
        call(0, digits, ans, temp, m);
        return ans;
    }
};