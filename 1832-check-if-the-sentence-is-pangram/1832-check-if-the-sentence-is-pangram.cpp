class Solution {
public:
    bool checkIfPangram(string sentence) {
        map<char, int> m;
        int count = 0;
        for(char i: sentence) 
            if(m[i] == 0) m[i]++, count++;
        if(count > 25) return true;
        return false;
    }
};