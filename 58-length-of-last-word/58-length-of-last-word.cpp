class Solution {
public:
    int lengthOfLastWord(string s) {
        int count = 0, counter = 0;
        for(int i=0;i<s.size();i++){
            cout<<counter<<" ";
            if(s[i] == ' ') 
                {
                if(count == 0) 
                {
                    count = 0;
                    continue;
                }
                else 
                {
                    counter = count;
                    count = 0;
                }
            }
            else count++;
        }
        if(count>0) return count;
        return counter;
    }
};