class Solution {
public:
    
    
    void constructLps(string n, vector<int>& lps) {
        int len = 0, i = 1;
        lps[0] = 0;
        while(i < n.size()) {
            if(n[i] == n[len]) {
                lps[i++] = ++len;
            }
            else {
                if(len > 0) len = lps[len-1];
                else lps[i++] = 0;
            }
        }
    }
    
    
    int strStr(string h, string n) {
           vector<int> lps(n.size());
        constructLps(n, lps);
        int i = 0, j = 0;
        while(i < h.size() && j < n.size()) {
            if(h[i] == n[j]) 
                i++,j++;
            if(j == n.size()) return i-j;
            else if(i < h.size() && h[i] != n[j])
                j ? j = lps[j-1] : i++;
        }
        return -1;
    }
};