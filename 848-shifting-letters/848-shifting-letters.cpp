class Solution {
public:
    string shiftingLetters(string s, vector<int>& shifts) {
        for(int i=shifts.size()-2;i>=0;i--){
            shifts[i]+= (shifts[i+1]);
            shifts[i]%=26;
        }
        for (int i=0;i<s.size();i++) {
            int x = s[i] -'a';
            x += shifts[i];
            x%=26;
            cout<<x<<" ";
            char y = (x) + 97;
            
            s[i] = y;
        }
        return s;
    }
};