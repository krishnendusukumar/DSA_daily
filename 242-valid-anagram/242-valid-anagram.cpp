class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size( )!=t.size()) return false;
        map<char, int> m1,m2;
        for(auto i:s) m1[i]++;
        for(auto j:t) m2[j]++;
        for(auto j:t) {
            if(m1[j] == m2[j]) continue;
            else return false;
        }
        return true;
    }
};