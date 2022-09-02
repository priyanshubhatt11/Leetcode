class Solution {
public:
    //We are moving from left to right and one column will have one queen 
    //So we only have to check left, top-left, bottom-left
    bool isvalid(int i,int j, vector<string> &board, int n){
        int row = i;
        int col = j;
        while(i>=0 && j>=0){
            if(board[i][j] == 'Q')return false;
            
            i--;j--;
        }
        i = row;
        j = col;
        while(j>=0){
            if(board[i][j] == 'Q')return false;
            j--;
        }
        i = row;
        j = col;
        while(i<n && j>=0){
            if(board[i][j] == 'Q')return false;
            i++;j--;
        }
        return true;
    }
    
    void solve(int j, vector<vector<string>> &ans, vector<string> &board, int n){
        if(j == n){ // one column will have only one queen so j = n
            ans.push_back(board);
            return;
        }
        for(int i=0;i<n;i++){
            if(isvalid(i,j,board,n)){
                board[i][j] = 'Q';
                solve(j+1,ans,board,n);
                board[i][j] = '.';
            }
        }
    } 
        
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> board(n);
        string s(n,'.');
        for(int i=0;i<n;i++){
            board[i] = s;
        }
        solve(0, ans, board, n);
        return ans;
    }
};