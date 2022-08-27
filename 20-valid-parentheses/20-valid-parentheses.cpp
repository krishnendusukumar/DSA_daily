class Solution {
public:
    bool isValid(string s) {
        unordered_map<char, int> m;
       m={{'{',-1}, {'(',-2},{'[',-3},{'}',1}, {')',2},{']',3}};
        stack<char> st;
        for (int i=0;i<s.size();i++)
        {
            if(m[s[i]]<0) st.push(s[i]);
            else {
                if(st.empty()) return false;
                char x=st.top();
                st.pop();
                if(m[s[i]]+m[x]!=0) return false;
            }
        }
        if(st.empty()) return true;
        else return false;
    }
};