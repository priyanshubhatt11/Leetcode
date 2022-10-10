class Solution {
public:
    
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
    
    TrieNode *root;
    Solution(){
        root = new TrieNode();
    }
    
    void insertWord(TrieNode *root , string word){
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
    
    string present(string word){
        TrieNode *temp = root;
        string s = "";
        for(int i=0;i<word.size();i++){
            int idx = word[i] - 'a';
            if(temp->child[idx] == NULL)break;
            temp = temp->child[idx];
            s += word[i];
            if(temp->isEnd == true)return s;
        }
        return word;
    }
    
    string replaceWords(vector<string>& dict, string sen) {
        for(auto i: dict){
             insertWord(root, i);
        }
        
        istringstream ss(sen);
        string word = "", ans = "";
        for( ;ss>>word; ){
            ans += present(word);
            ans += ' ';
        }
        ans.pop_back();
        
        return ans;
        
        
    }
};








