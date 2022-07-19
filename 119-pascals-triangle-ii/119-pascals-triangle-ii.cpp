class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> temp(rowIndex+1, -1);
        int i = 0;
        while(i <= rowIndex) {
            vector<int> ans;
            for (int j = 0; j <= i; j++) {
                if(j == 0 || j == i) ans.push_back(1);
                else ans.push_back(temp[j] + temp[j-1]);
            }
            for(int j = 0; j < ans.size(); j++) {
                temp[j] = ans[j];
            }
            i++;
        }
        return temp;
    }
};