class Solution {
public:
    class Trie{ 
        public:
        Trie *child[26];
        bool isEnd;
        // one another solution is make
        Trie(){
            for(int i=0;i<26;i++){
                child[i] = NULL;
            }
            isEnd = false;
        }
    };
    Trie* root;
    Solution(){
        root = new Trie();
    }
    
    void insert(string s){
        Trie *temp = root;
        for(int i=0;i<s.size();i++){
            int idx = s[i] - 'a';
            if(temp->child[idx] == NULL){
                temp->child[idx] = new Trie();
            }
            temp = temp->child[idx];
        }
        temp->isEnd = true;
    }    
    
    /********************************************************************************************/
    int n,m;
    vector<vector<bool>> vis;
    void solve(vector<vector<char>> &board, int i, int j, string s , Trie *root , vector<string> &ans){
        if(i < 0 || i >= n || j < 0 || j >= m || vis[i][j] == true || root->child[ board[i][j]- 'a' ] == NULL)  return;
        //cout<<s<<" ";
        root = root->child[ board[i][j] - 'a'];
        if(root->isEnd == true){
            ans.push_back(s + board[i][j]);
            root->isEnd = false;
            //return;
        }
        vis[i][j] = true;
        s.push_back(board[i][j]);
        solve(board, i+1, j , s  , root,  ans);
        solve(board, i, j+1 , s , root,  ans);
        solve(board, i-1, j , s , root, ans);
        solve(board, i, j-1 , s , root,  ans);
        
        vis[i][j] = false;
    }
    
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        
        for(auto i: words){
            insert(i);
        }
        n = board.size(), m = board[0].size();
        vis.resize(n, vector<bool>(m, false));
        
        
        vector<string> ans;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                char x = board[i][j];
                if(root->child[x - 'a'] != NULL){ //  check word present or not
                    //Trie *temp = root;
                    solve(board, i, j, "", root,  ans);
                }
            }
        }
        return ans;
    }
};
/**************************************************************************************/





