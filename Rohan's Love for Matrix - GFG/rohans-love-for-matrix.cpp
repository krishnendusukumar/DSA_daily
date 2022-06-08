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
        long long prev = 0, prev1 = 1;
        for (int i = 2;i <= n; i++){
            long long element = (prev + prev1)%1000000007;
            prev = prev1, prev1 = element;
        }
        return prev1;
        
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