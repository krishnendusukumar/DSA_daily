class Solution {
public:
    
    void helper(int n, int k, vector<int> &v, int j, int count){
        if(count == n) return;
        int x = k-1;
         j = (j + x);
        cout<<j<<" ";
        j%=v.size();
        v.erase(v.begin()+j);
        count++;
        helper(n, k, v, j, count);
    }
    
    int findTheWinner(int n, int k) {
        vector<int> v;
        for(int i = 0;i<n;i++) {v.push_back(i+1);}
        helper(n, k,v, 0, 1);
        return v[0];
    }
};