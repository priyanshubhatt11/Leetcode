class Trie{
    public:
    Trie *child[26];
    bool isEnd;
    int count;
    Trie(){
        for(int i=0;i<26;i++){
            child[i] = NULL;
        }
        count=0;
        isEnd = true;
    }
};

class Solution {
public:
    
    Trie *root;
    Solution(){
        root = new Trie();
    }
    
    void insert(Trie*root , string s){
        Trie*temp = root;
        for(int i=0;i<s.size();i++){
            int idx = s[i] - 'a';
            if(temp->child[idx] == NULL){
                temp->child[idx] = new Trie();
            }
            temp = temp->child[idx];
            temp->count++;
        }
        temp->isEnd = true;
    }
    
    int findPrefix(Trie* root, string s){
        int sum =0;
        Trie *temp = root;
        for(int i=0;i<s.size();i++){
            int idx = s[i] - 'a';
            if(temp->child[idx] == NULL)return sum;
            temp = temp->child[idx];
            sum += temp->count;
        }
        return sum;
    }
    
    vector<int> sumPrefixScores(vector<string>& words) {
        for(string i: words){
            insert(root, i);
        }   
        int n = words.size();
        vector<int> ans(n);
        
        for(int i=0;i<n;i++){
            ans[i] = findPrefix(root, words[i]);
        }
        return ans;
    }
};










