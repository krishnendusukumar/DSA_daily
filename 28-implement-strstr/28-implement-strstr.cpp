class Solution {
public:
    int strStr(string h, string n) {
        if(h.size() < n.size()) return -1;
        
        for(int i=0;i <= h.size() - n.size(); i++) {
           bool flag = true;
            for(int j = 0; j < n.size();j++) {
                if(n[j]!=h[j+i]) flag = false;
            }
            if(flag) return i;
        }
        return -1;
    }
};