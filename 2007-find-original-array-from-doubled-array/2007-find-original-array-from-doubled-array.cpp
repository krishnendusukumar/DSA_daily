class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed) {
        int n = changed.size();
        if (n % 2 == 1) return {};
        sort(changed.begin(), changed.end());
        vector<int> arr;
        map<int,int> m;
        for(int i: changed) m[i]++;
        for(int i: changed) {
            if(m[i] > 0) {
                if(m[i] == 0) continue;
                if(m[i*2] == 0) return {};
                arr.push_back(i);
                m[i]--;
                m[i*2]--;
            }
        }
        return arr;
    }
};