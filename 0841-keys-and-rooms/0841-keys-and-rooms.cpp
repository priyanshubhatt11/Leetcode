class Solution {
public:
    
    void solve(vector<vector<int>> &r, vector<bool> &vis, int idx){
        if(vis[idx] )return ;
        vis[idx] = true;
        for(auto i:r[idx]){
            solve(r, vis, i);
        }
    }
    
    bool canVisitAllRooms(vector<vector<int>>& r) {
        int n = r.size();
        vector<bool> vis(n,false);
        solve(r, vis, 0);
        
        for(auto i:vis) if(i == false)return false;
        return true;
        
    }
};