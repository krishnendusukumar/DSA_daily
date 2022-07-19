class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        
        vector<vector<int>> v;
        vector<int> temp(numRows, 0);
        temp.push_back(1);
        for(int i=1;i <= numRows; i++) {
            
            vector<int> ans;
            
            for(int j = 0; j < i; j++) {
                
                if(j == 0 || j == i-1) ans.push_back(1);
                
                else ans.push_back(temp[j] + temp[j-1]);
            }
            
            for(int i=0;i < ans.size(); i++)
                temp[i] = ans[i];
            
            v.push_back(ans);
        }
        return v;
    }
};