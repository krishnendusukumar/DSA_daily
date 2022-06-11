class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int i=0, j=0, ans = 0;
        set < char > m;
        while(i<s.size() && j<s.size()){
            if(m.find(s[i]) == m.end()){
                m.insert(s[i++]);
                 ans = max(ans, i-j);
            }
            else {
                  m.erase(s[j++]);
            }
        }
        return ans;
    }
};