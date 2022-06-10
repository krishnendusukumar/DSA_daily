class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int length = 0;
        for(int i=0;i<s.size();i++){
            int count = 0;
            unordered_map<char, int> m;
            int j = i;
            while(j<s.size()){
                m[s[j]]++;
                if(m[s[j]] > 1) break;
                count++;
                j++;
            }
            length = max(length, count);
        }
        return length;
    }
};