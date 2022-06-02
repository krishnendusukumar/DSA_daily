class Solution {
public:
    bool canConstruct(string a, string b) {
        unordered_map<char,int> m;
        for(int i=0;i<b.size();i++) m[b[i]]++;
        for(int i = 0;i<a.size();i++)
        {
            if(m[a[i]]>0)
                {
                m[a[i]]--;
                continue;
            }
            else {
             return false;            }
        }
        return true;
    }
};