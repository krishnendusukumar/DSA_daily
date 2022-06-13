class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<int> mini(triangle.back());
        for(int i = n-2;i>=0;i--){
            for(int j = 0;j<triangle[i].size();j++){
                mini[j] = min(mini[j], mini[j+1]) + triangle[i][j];
            }
        }
        return mini[0];
    }
};