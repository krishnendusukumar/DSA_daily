// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends

class Solution{
  public:
    //Function to count subarrays with 1s and 0s.
    long long int countSubarrWithEqualZeroAndOne(int arr[], int n)
    {
        //Your code here
        
        for(int i = 0;i < n;i++){
            if(arr[i] == 0) arr[i] = -1;
        }
        int sum = 0,count = 0;
        unordered_map<int,int> m;
        m[0] = 1;
        for (int i = 0; i < n; i++){
            sum += arr[i];
            m[sum]++;
            if(m[sum]>1)
            count+=m[sum],count -=1;
        }
        return count;
    }
};

// { Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	int n,i;
	cin>>n;
	int arr[n];
	for(i=0;i<n;i++)
	cin>>arr[i];
	Solution obj;
	cout<< obj.countSubarrWithEqualZeroAndOne(arr, n)<<"\n";
	}
	return 0;
}
  // } Driver Code Ends