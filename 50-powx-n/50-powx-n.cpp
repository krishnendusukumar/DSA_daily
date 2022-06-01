class Solution {
public:
    
   
double myPow(double x, int n) {
    if (n == INT_MAX) return x;
    else if (n == INT_MIN) return (x == 1 || x == -1) ? 1 : 0;
    if(n<0) x=1/x, n*=-1;
    double ans = 1;
    for(int i=0;i<n;i++)
        ans = ans*x;
    return ans;
}
};