// { Driver Code Starts
//Initial function template for C++

#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template for C++

class Solution{
    public:
    // arr : given array
    // l : starting index of the array i.e 0
    // r : ending index of the array i.e size-1
    // k : find kth smallest element and return using this function
    
    void swap(int arr[], int i, int j){
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
    
    
    int randomCall(int arr[], int l, int r){
        int piv = rand() % (r-l+1);
        swap(arr, l + piv, r);
        return partition(arr, l, r);
    }
    
    
    int partition(int arr[], int l , int r){
        int i=l-1, j=l;
        int pivot = arr[r];
        for (j=l;j<r;j++){
            if(arr[j]<pivot)
            i++, swap(arr, i, j);
        }
        swap(arr, i+1 , j);
        return i+1;
    }
    
    int kthSmallest(int arr[], int l, int r, int k) {
        //code here
        
        int pos = randomCall(arr, l , r);
        
        if(pos == k-1) return arr[pos];
        else if(pos > k-1 ){
            kthSmallest(arr, l ,pos-1, k);
        }
        else kthSmallest(arr, pos+1, r, k);
        
    }
};

// { Driver Code Starts.
 
int main()
{
    int test_case;
    cin>>test_case;
    while(test_case--)
    {
        int number_of_elements;
        cin>>number_of_elements;
        int a[number_of_elements];
        
        for(int i=0;i<number_of_elements;i++)
            cin>>a[i];
            
        int k;
        cin>>k;
        Solution ob;
        cout<<ob.kthSmallest(a, 0, number_of_elements-1, k)<<endl;
    }
    return 0;
}  // } Driver Code Ends