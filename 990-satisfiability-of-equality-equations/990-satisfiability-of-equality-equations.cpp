class Solution {
public:
    int par[26];
    
    int find(int x){
        if(par[x] == x)return x;
        return find(par[x]);
    }
    bool equationsPossible(vector<string>& eq) {
        for(int i=0;i<26;i++){
            par[i] = i;
        }
        
        for(auto i: eq){
            if(i[1] == '='){
                par[find(i[3] - 'a')] = find(i[0]- 'a');
            }
        }
        for(auto i:eq){
            if(i[1] == '!' && find(i[0] - 'a') == find(i[3] - 'a'))return false;
        }
        
        return true;
    }
};