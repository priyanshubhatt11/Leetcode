class Solution {
public:
    int n,m;
    
    bool solve(vector<vector<char>> &board, string s,int i, int j, int idx , vector<vector<bool>>&vis){
        if(idx == s.size())return true;
        if(i<0 || i>=n || j<0 || j>=m || board[i][j] != s[idx] || vis[i][j] )return false;
        
        vis[i][j] = true;
        bool d = solve(board, s, i+1, j , idx+1, vis);
        bool u = solve(board, s, i-1, j, idx+1, vis);
        bool r = solve(board, s , i, j+1, idx+1, vis);
        bool l = solve(board, s, i , j-1, idx+1,  vis);
        vis[i][j] = false;
        return d || u || r || l;
        
    }
    
    bool exist(vector<vector<char>>& board, string word) {
        n = board.size(), m = board[0].size();
        vector<vector<bool>> vis(n, vector<bool> (m, false));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j] == word[0]){
                    if(solve(board, word, i, j, 0,  vis))return true;
                }
            }
        }
        
        return false;
    }
};