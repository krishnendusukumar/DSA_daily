class Solution {
public:
    
    void dfs(int i, int j, vector<vector<char>>& grid) {
        
        int n = grid.size();
        int m = grid[0].size();
        
        if(i < 0 || j < 0 || i >= n || j >= m || grid[i][j] != '1') return;
        if(grid[i][j] == '1') grid[i][j] = '2';
        
        dfs(i-1, j, grid);
        dfs(i+1, j, grid);
        dfs(i, j+1, grid);
        dfs(i, j-1, grid);
    return; 
    }
    
    int numIslands(vector<vector<char>>& grid) {
        int count = 0;
       for(int i= 0; i < grid.size(); i++) {
           for(int j = 0; j < grid[0].size(); j++) {
               if(grid[i][j] == '1') 
               {
                   dfs(i,j, grid);
                   count++;
               }
           }
       } 
        return count;
    }
};