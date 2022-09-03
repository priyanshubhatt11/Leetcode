class Solution {
public:
    int ans =0 ;
    
    bool isvalid(vector<string> &board, int i , int j , int n){
        int row = i;
        int col = j;
        while(i >=0 && j>=0){
            if(board[i][j] == 'Q')return false;
            i--;j--;
        }
        i=row;
        j=col;
        while( j>=0){
            if(board[i][j] == 'Q')return false;
            
            j--;
        }
        i = row;
        j= col;
        while(i <n && j>=0){
            if(board[i][j] == 'Q')return false;
            
            i++;j--;
        }
        
        return true;
    }
    
    void solve(int n,int col, vector<string> &board){
        if(col == n){
            ans++;
            return;
        }
        //cout<<"f ";
        for(int row =0;row <n;row++){
            if(isvalid(board, row, col, n)){
                board[row][col] = 'Q';
                solve(n, col+1, board);
                board[row][col] = '.';
            }
        }
    }
        
        
    int totalNQueens(int n) {
        
        vector<string> board(n);
        string s(n, '.');
        
        for(int i=0;i<n;i++){
            board[i] = s;
        }
        
        solve(n, 0, board);
        return ans;
    }
};