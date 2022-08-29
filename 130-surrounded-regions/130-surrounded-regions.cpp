class Solution {
public:
    
    void dfs(int i, int j, int n, int m, vector<vector<char>>& board) {
        
        if(i < 0 || j < 0 || i >= n || j >= m || board[i][j] != 'O') return;
        board[i][j] = '#';
        dfs(i-1, j, n, m, board);
        dfs(i+1, j, n, m, board);
        dfs(i, j+1, n, m , board);
        dfs(i, j-1, n, m, board);
        
        
    }
    
    void solve(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();
        
    for(int i = 0; i < n; i++) {
        if(board[i][0] == 'O') dfs(i, 0, n, m, board);
        if(board[i][m-1] == 'O') dfs(i,m-1, n, m, board);
    }
        for(int i = 0; i < m; i++) {
        if(board[0][i] == 'O') dfs(0, i, n, m, board);
        if(board[n-1][i] == 'O') dfs(n-1,i, n, m, board);
    }
        
        for(int i = 0; i < n; i++) {
             for(int j = 0 ;j < m; j++) {
                 if(board[i][j] == 'O') board[i][j] = 'X';
                 if(board[i][j] == '#') board[i][j] = 'O';
             }
        }
    }
};


 // o o o 
 // o o o 
 // o o o
// x x x x 
// x o o x 
// x x o x
// x o x x


// O X X O X
// X O O X O
// X O X O X
// O X O O O
// X X O X O