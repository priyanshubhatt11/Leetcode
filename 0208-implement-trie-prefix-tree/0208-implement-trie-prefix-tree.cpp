class Trie {
    class TrieNode{
            public:
            TrieNode* child[26];
            bool isEnd;
            TrieNode(){
                for(int i=0;i<26;i++){
                    child[i] = NULL;
                }
                isEnd = false;
            }
        };
    public:
    TrieNode *root;
    Trie() {
        root = new TrieNode();        
    }
    
    void insert(string word) {
        TrieNode* temp = root;
        for(int i=0;i<word.size();i++){
            int idx = word[i] - 'a';
            if(temp->child[idx] == NULL){
                temp->child[idx] = new TrieNode();
            }
            temp = temp->child[idx];
        }
        temp->isEnd = true;
    }
    
    bool search(string word) {
        TrieNode* temp = root;
        for(int i=0;i<word.size();i++){
            int idx = word[i] - 'a';
            if(temp->child[idx] == NULL)return false;
            
            temp = temp->child[idx];
        }
        return temp->isEnd;
    }
    
    bool startsWith(string pre) {
        TrieNode *temp = root;
        for(int i=0;i<pre.size();i++){
            
            int idx = pre[i] - 'a';
            if(temp->child[idx] == NULL)return false;
            temp = temp->child[idx];
        }
        return true;
    }
};








