class Solution {
public:
    
     bool safe(int row, int col, vector<string> board, int n ){
        int r = row, c = col;
        while(row>=0 && col >=0){
            if(board[row][col] == 'Q') return false;
                col--; row--;
        }
        row = r, col = c;
        while(col>=0){
            if(board[row][col] == 'Q') return false;
                col--;
        }
         row = r, col = c;
        while(row<n && col>=0){
            if(board[row][col] == 'Q') return false;
                row++; col--;
        }
        return true;
    }
    
    int solve(int col, vector < string > & board, int n){
        if(col == n) {return 1;}
        int count = 0;
        for(int row=0;row<n;row++){
            if(safe(row, col, board, n)){
                board[row][col] = 'Q';
                count+=solve(col+1, board, n);
                board[row][col] = '.';
            }
        }
        return count;
    }
    
    int totalNQueens(int n) {
        vector<string> board(n);
        string s(n, '.');
        for (int i=0;i<n;i++) board[i] = s;
        return solve(0, board, n);
    }
};