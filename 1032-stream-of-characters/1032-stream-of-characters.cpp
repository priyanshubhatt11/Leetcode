class StreamChecker {
public:
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

   
    Trie* root;
    
    void insert(string &s){
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
    
    bool solve(string &s){
        Trie *temp = root;
        for(int i=s.size()-1;i>=0;i--){
            int idx = s[i] - 'a';
            if(temp->child[idx] == NULL)return false;
            temp = temp->child[idx];
            
            if(temp->isEnd == true)return true;
        }
        return false;
     }
    
    StreamChecker(vector<string>& words) {
        root = new Trie();
        for(auto &i:words){
            reverse(i.begin(), i.end());
            insert(i);
        }
    }
    
    string s = "";
    
    bool query(char letter) {
        s.push_back(letter);
        return solve(s);
        
    }
};




















