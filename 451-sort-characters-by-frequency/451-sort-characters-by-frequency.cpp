class Solution {
public:
    
    static bool cmp(pair<char, int> p1,pair<char, int> p2){
        if(p1.second > p2.second) return true;
        return false;
    }
    
    string frequencySort(string s) {
        map<char, int> m;
        for(int i=0;i<s.size();i++) m[s[i]]++;
        string ans="";
        vector<pair<char, int>> p1;
        for(auto it:m){
            p1.push_back({it.first, it.second});
        }
        sort(p1.begin(), p1.end(), cmp);
        for (auto it:p1){
            while(it.second-->0) ans+=it.first;
        }
        return ans;
    }
};