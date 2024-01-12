class Solution {
public:
    // a b c e
    // 3 2 2 1
    // 
    int minDeletions(string s) {
        vector<int> vec(26,0);
        for(auto &i:s){
            vec[i-'a']++;
        }
        
        int ans =0;
        unordered_map<int,int> mp;
        
        for(int i=0;i<26;i++){
            int x = vec[i];
            if(x == 0)continue;            
            if(mp.find(x) != mp.end()){
                
                while(x>0 && mp.find(x) != mp.end()){
                    ans++;
                    x--;
                }
            }
            mp[x]++;
            
        }
        return ans;
        
        
        
    }
};














