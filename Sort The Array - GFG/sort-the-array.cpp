// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution{
    public:
    
    void swap(vector<int> &arr, int i, int j){
        int temp = arr[j];
        arr[j] = arr[i];
        arr[i] = temp;
    }
    
    int partition(vector<int> &arr, int l , int r){
        int i=l-1;
        int j=l;
        int pivot = arr[r];
        
        for (j=l;j<r;j++){
            if(arr[j] < pivot) 
               i++, swap(arr, i, j);
        }
        swap(arr, i+1, j);
        return i+1;
    }
    
    void quicksort(vector<int> &arr, int l, int r){
    if(l<r)
    {
        int piv=partition(arr, l, r);
    
    quicksort(arr, l, piv-1);
    quicksort(arr, piv+1, r);
        
    }
    
    }
    
    vector<int> sortArr(vector<int> arr, int n){
    //complete the function here
    
    quicksort(arr, 0 , n-1);
    return arr;
    }
};

// { Driver Code Starts.
int main(){
    
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int>s(n);
        for(int i = 0; i < n; i++)
            cin >> s[i];
        Solution ob;
        vector<int>v = ob.sortArr(s, n);
        for(auto i : v)
            cout << i << ' ';
        cout << endl;
    }
return 0;
}

  // } Driver Code Ends