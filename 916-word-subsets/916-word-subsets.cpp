class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        vector<char> v(26, -1);
        vector<string> ans;
        for(auto i: words2) {
            vector<int> temp(26, -1);
            for(auto j:i) {
                temp[j-'a']+=1;
            }
            for(int i=0;i < 26;i++) {
                if(v[i]<temp[i]) v[i] = temp[i];
            }
        }
        for(auto i: words1) {
            vector<int>count(26, -1);
            bool flag = true;
            for(auto j: i) {
                count[j-'a']++;
            }
            for(int j=0; j < 26;j++) {
                if(v[j] != -1){
                    if(v[j] > count[j]) flag = false;
                }
            }
            if(flag) ans.push_back(i);
        }
        return ans;
    }
};