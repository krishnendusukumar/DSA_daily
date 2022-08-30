class Solution {
public:
    
     bool helper(vector<vector<int>>& matrix, vector<vector<int>> res) {
        
           reverse(matrix.begin(), matrix.end());
    for (int i = 0; i < matrix.size(); ++i) {
        for (int j = i + 1; j < matrix[i].size(); ++j)
            swap(matrix[i][j], matrix[j][i]);
    }
         return matrix == res;
    }
    
    bool findRotation(vector<vector<int>>& matrix, vector<vector<int>>& target) {
      
        if(helper(matrix, target) || helper(matrix, target) || helper(matrix, target) || helper(matrix, target)) return true;
        return false;
    }
};