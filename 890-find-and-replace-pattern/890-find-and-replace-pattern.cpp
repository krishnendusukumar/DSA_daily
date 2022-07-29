class Solution {
public:
    
    bool helper(string a, string b) {
        unordered_map<char, char> m;
        unordered_map<char, int> m2;
        for(int i =0;i < a.size();i++) {
            if(!m[a[i]]){
                if(m2[b[i]] == 0) 
                    m[a[i]] = b[i], m2[b[i]] = 1;
                else return false;
            }
             else {
                 if(m[a[i]] != b[i]) return false;
             }
        }
        return true;
    }
    
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        vector<string> ans;
        for(auto i:words) {
            if(helper(i, pattern) == true) ans.push_back(i);
        }
        return ans;
    }
};