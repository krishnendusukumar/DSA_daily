// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
	public:
	
	vector<string> call(string s, int i){
        if(i>=s.size()) {
            vector<string> s;
            s.push_back("");
            return s;
        };
     vector<string>par = call(s, i+1);
        vector<string>ans;
        for (auto j:par){string s1="";
            s1=s[i]+j;
            ans.push_back(s1);
        }
         for (auto j:par) ans.push_back(j);
        return ans;
    }
	
		vector<string> AllPossibleStrings(string s){
		    // Code here
		    vector<string> ans = call(s, 0);
		    sort(ans.begin(),ans.end());
		    ans.erase(ans.begin());
		    return ans;
		}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string s;
		cin >> s;
		Solution ob;
		vector<string> res = ob.AllPossibleStrings(s);
		for(auto i : res)
			cout << i <<" ";
		cout << "\n";

	}
	return 0;
}  // } Driver Code Ends