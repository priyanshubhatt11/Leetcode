class Trie{
    public:
    Trie *child[10];
    bool isEnd;
    Trie(){
        for(int i=0;i<10;i++){
            child[i] = NULL;
        }
        isEnd = false;
    }
};

class Solution {
public:
    
    Trie *root;
    Solution(){
        root = new Trie();
    }
    
    void insert(Trie *root, int n){
        Trie *temp = root;
        string s = to_string(n);
        for(int i=0;i<s.size();i++){
            int idx = s[i] - '0';
            if(temp->child[idx] == NULL){
                temp->child[idx] = new Trie();
            }
            temp = temp->child[idx];
        }
        temp->isEnd = true;
    }
    
    void solve(Trie *root, vector<int> &ans, string s){
        if(root == NULL)return;
        
        if(root->isEnd == true){
            //cout<s<<" ";
            ans.push_back(stoi(s));
        }
        
        for(int i=0;i<10;i++){
            if(root->child[i] != NULL){
                
                solve(root->child[i], ans,s+to_string(i));
            }
        }
    }
    
    
    vector<int> lexicalOrder(int n) {
        for(int i=1;i<=n;i++){
            insert(root, i);
        }
        vector<int> ans;
        solve(root, ans, "");
        return ans;
    }
};












