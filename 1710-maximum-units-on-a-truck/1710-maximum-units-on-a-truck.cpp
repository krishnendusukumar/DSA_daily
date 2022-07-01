class Solution {
public:
    
    static bool cmp(vector<int> &a , vector<int> & b){
        return a[1]>b[1];
    }
    int maximumUnits(vector<vector<int>>& a, int n) {
        int sum = 0;
        sort(a.begin(), a.end(), cmp);
        for(int i=0;i<a.size();i++) {
            if(n == 0) continue;
            else {
                if(n > a[i][0]) {
                    sum += a[i][0]*a[i][1];
                    n-= a[i][0];
                }
                else {
                    sum += n*a[i][1];
                    return sum;
                }
            }
        }
        return sum;
    }
};