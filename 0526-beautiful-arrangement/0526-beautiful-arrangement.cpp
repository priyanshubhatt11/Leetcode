class Solution {
public:
    // similar to find all permutation
    int ans =0;
    void solve(int idx, int n, vector<bool>&vis){
        if(idx == n+1){
            ans++;
            return;
        }
        
        for(int i=1;i<=n;i++){
            if(!vis[i] && (idx%i == 0 || i%idx == 0)){
                vis[i] = true;
                solve(idx+1, n, vis);
                vis[i] = false;
            }
        }
    }
    
    int countArrangement(int n) {
        vector<bool> vis(n+1, false);
        solve(1, n, vis);
        return ans;
    }
};