class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int i = 0, j = matrix.size()-1;
        while(i < j) {
            swap(matrix[i++], matrix[j--]);
        }
        
        for(int x = 0; x < matrix.size(); x++) {
            for(int y = x+1; y < matrix[x].size(); y++) {
                swap(matrix[x][y], matrix[y][x]);
            }
        }
    }
};