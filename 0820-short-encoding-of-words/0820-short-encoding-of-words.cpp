class Trie{
    public:
    Trie* child[26];
    bool isEnd;
    Trie(){
        for(int i=0;i<26;i++){
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
    
    void insert(string s){
        Trie *temp = root;  
        for(int i=s.size()-1;i>=0;i--){        // Inserted in reverse order
            int idx = s[i] - 'a';
            if(temp->child[idx] == NULL){
                temp->child[idx] = new Trie();
            }
            temp = temp->child[idx];
        }
        temp->isEnd = true;
    }
    
    int ans=0;
    void findd(Trie *root, int c){
        bool last = false;  // to check the end
        for(int i=0; i<26;i++){
            if(root->child[i] != NULL){
                //cout<<(char)(i+'a');
                findd(root->child[i] , c+1);
                last = true;
            }
        }
        if(last == false){
            ans+= c+1;
        }
        
    }
        
    int minimumLengthEncoding(vector<string>& words) {
        for(auto i:words){
            insert(i);      
        }   
        
        findd(root, 0);
        return ans;
    }
};










