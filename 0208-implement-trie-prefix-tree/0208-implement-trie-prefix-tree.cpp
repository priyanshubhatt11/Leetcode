class TrieNode{
    public:
    char data;
    TrieNode *child[26];
    bool isEnd;
    TrieNode(char ch){
        data = ch;
        for(int i=0;i<26;i++){
            child[i] = NULL;
        }
        isEnd = false;
    }
};

class Trie {
public:
    TrieNode* root;
    Trie() {    
        root = new TrieNode('\0');
    }
    
    /***********************************/
    void insertUtil(TrieNode* root, string word){
        
        if(word.length() == 0){
            root->isEnd = true;
            return;
        }
        
        TrieNode* temp;
        int idx = word[0] - 'a';
        if(root->child[idx] != NULL){
            temp = root->child[idx];
        }
        else{
            temp = new TrieNode(word[0]);
            root->child[idx] = temp;
        }
        insertUtil(temp , word.substr(1));
        
    }
    
    void insert(string word) {
        insertUtil(root, word); 
    }
    /*************************************/
    
    bool searchUtil(TrieNode *root, string word){
        //cout<<word<<" ";
        if(word.length() == 0){
            return root->isEnd;
        }
        
        TrieNode *temp;
        int idx = word[0] - 'a';
        if(root->child[idx] != NULL){
            temp = root->child[idx];
        }        
        else{
            return false;
        }
        
        return searchUtil(temp, word.substr(1));
        
    }
    bool search(string word) {
        return searchUtil(root, word);
    }
    
    /**************************************/
    bool startsWithUtil(TrieNode *root, string pre){
        if(pre.length() == 0){
            return true;
        }
        TrieNode *temp;
        int idx = pre[0] - 'a';
        if(root->child[idx] != NULL){
            temp = root->child[idx];
        }
        else{
            return false;
        }
        return startsWithUtil(temp , pre.substr(1));
    }
    
    bool startsWith(string prefix) {
        return startsWithUtil(root, prefix);
    }
    /*************************************/
};


/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */