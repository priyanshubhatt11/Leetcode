class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int n = board.size();
        unordered_map<char, int> rows[9];
        unordered_map<char, int> cols[9];
        unordered_map<char, int> group[9];
        
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(board[i][j] == '.')continue;
                char ch = board[i][j];
                if(rows[i][ch]++ > 0 || cols[j][ch]++ > 0 || group[(i/3) * 3 + j/3][ch]++ >0)return false; 
            }
        }
        return true;
        
    }
};