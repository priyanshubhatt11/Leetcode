// one solution is by using set

// In trie count node that are not null and atmost k are divisible by p;

class Solution {
public:
    
    class Trie{
        public:
        unordered_map<int,Trie*>child;
        
        
    };
    Trie* root ;
    Solution(){
        root = new Trie();
    }
    
    int count=0;
    void insert(vector<int>&nums, int k, int p){
        
        int c =0;
        for(int i=0;i<nums.size();i++){
            Trie*temp = root;
            c=0;
            for(int j=i;j<nums.size();j++){
                if(nums[j] %p == 0)c++;
                if(c>k)break;
                if(temp->child[nums[j]] == NULL){
                    count++;
                    temp->child[nums[j]] = new Trie();
                }
                temp = temp->child[nums[j]];
            }
        }
    }
    
    
    
    int countDistinct(vector<int>& nums, int k, int p) {
        
        insert(nums, k, p);
        
        return count;
    }
};































