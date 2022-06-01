// { Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function Template for C++
class Solution {
  public:
  
    int firstElement(int n) 
    {
        // code here
        long long sum = 0;
        vector<int> v;
        v.push_back(0);
        v.push_back(1);
        for (int i = 2;i <= n; i++){
            long long element = (v[i-1] + v[i-2])%1000000007;
            v.push_back(element);
        }
        return v[v.size()-1];
        
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int  n;
        cin >> n ;
        Solution ob;
        cout<<ob.firstElement(n)<<endl;
    }
    return 0;
}
  // } Driver Code Ends