class WordDictionary {
public:
    class TrieNode{
        public:
            TrieNode *child[26];
            bool isEnd;
            TrieNode(){
                for(int i=0;i<26;i++){
                    child[i] = NULL;
                }
                isEnd = false;
            }
    };
    
    TrieNode *root;
    WordDictionary() {
        root = new TrieNode();
    }
    
    void addWord(string word) {
        TrieNode*temp = root;
        for(int i=0;i<word.size();i++){
            int idx = word[i] - 'a';
            if(temp->child[idx] == NULL){
                temp->child[idx] = new TrieNode();
            }
            temp = temp->child[idx];
        }
        temp->isEnd = true;
    }
    
    bool findd(TrieNode *temp , string &word, int idx){
        if(idx == word.size())return temp->isEnd;
        
        if(word[idx] == '.'){
            for(int i=0;i<26;i++){
                if(temp->child[i] && findd(temp->child[i], word, idx+1))return true;
            }
        }
        else{
            int i = word[idx] - 'a';
            if(temp->child[i] && findd(temp->child[i], word, idx+1))return true;
        }        
        return false;
    }
    
    bool search(string word) {
        TrieNode *temp = root;
        
        // for(int i=0;i<word.size();i++){
        //     if(word[i] == '.')return false;
        //     int idx = word[i] - 'a';
        //     if(temp->child[idx] == NULL)return false;
        //     temp = temp->child[idx];
        // }
        return findd(temp, word, 0);
        
    }
};









