class Solution {
public:
    int minReorder(int n, vector<vector<int>>& conn) {
        vector<pair<int,int>> vec[n+1];
        for(auto i:conn){
            vec[i[0]].push_back({i[1], 1});
            vec[i[1]].push_back({i[0], 0});
        }

        
        queue<int> q;
        q.push(0);
        
        int ans =0;
        vector<bool> vis(n+1, false);
        vis[0] = true;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            for(auto i:vec[node]){
                if(!vis[i.first]){
                    vis[i.first] = true;
                    ans += i.second;
                    q.push(i.first);
                }
            }
            
        }
        return ans;
    }
};