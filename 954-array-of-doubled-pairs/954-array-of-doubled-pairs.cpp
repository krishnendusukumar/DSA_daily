class Solution {
public:
    // bool canReorderDoubled(vector<int>& arr) {
    //     int n = arr.size();
    //     map<int,int> m;
    //     for(int i = 0; i < n; i++) 
    //         m[arr[i]]++;
    //     sort(arr.begin(), arr.end(), [](int i, int j) {return abs(i) < abs(j);});
    //     for (int x : arr) {
    //         cout<<m[x]<<" ";
    //         if (m[x] > m[2 * x])
    //             return false;
    //         m[2 * x] -= m[x];
    //     }
    //     return true;
    // }
     bool canReorderDoubled(vector<int>& A) {
        unordered_map<int, int> c;
        for (int a : A) c[a]++;
        vector<int> keys;
        for (auto it : c)
            keys.push_back(it.first);
        sort(keys.begin(), keys.end(), [](int i, int j) {return abs(i) < abs(j);});
        for (int x : keys) {
            if (c[x] > c[2 * x])
                return false;
            c[2 * x] -= c[x];
        }
        return true;
    }
};