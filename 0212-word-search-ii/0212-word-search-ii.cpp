class Trie{
        public:
        Trie *child[26];
        bool isEnd;
        string str;
        
        Trie(){
            for(int i=0;i<26;i++){
                child[i] = NULL;
            }
            isEnd = false;
        }
        
};
class Solution {
    public:
    
    
    Solution(){
        root = new Trie();
    }
    Trie* root;
    
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
        temp->str = s;
    }
    
    vector<string> ans;
    vector<vector<bool>> vis;
    void solve(vector<vector<char>>&board, int i,int j, Trie *root){
        
        if(i<0 || i>=board.size() || j<0 || j>=board[0].size() || vis[i][j] == true || root->child[board[i][j] - 'a'] == NULL)return;
        root = root->child[board[i][j] - 'a'];
        if(root->isEnd == true){
            //cout<<"A";
            ans.push_back(root->str);
            root->isEnd = false;
        }
        vis[i][j] = true;
        solve(board, i+1, j, root);
        solve(board, i, j+1, root);
        solve(board, i-1, j, root);
        solve(board, i, j-1, root);
        vis[i][j] = false;
    }

    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        for(auto i:words){
            insert(i);
        }
        
        int n=board.size(), m = board[0].size();
        vis.resize(n, vector<bool> (m, false));
        //vector<string> ans;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                int idx = board[i][j] - 'a';
                if(root->child[idx] != NULL){
                    //cout<<i<<" "<<j;
                    Trie *temp = root;
                    solve(board, i, j ,temp);
                }
            }
        }
        
        
        
        return ans;
    }
};






















