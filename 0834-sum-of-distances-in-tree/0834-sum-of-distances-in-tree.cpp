class Solution {
public:
    vector<vector<int>> g;
    vector<int> count,ans;
    void dfs(int node,int p=-1)
    {
        for(auto &u:g[node])
        {
            if(u==p) continue;
            dfs(u,node);
            count[node]+=count[u];
            ans[node]+=ans[u]+count[u];
        }
        count[node]+=1;
    }
    void dfs2(int node,int n,int p=-1)
    {
        for(auto &u:g[node])
        {
            if(u==p) continue;
            //Suppose we shift the root from root 0 to 1, what changes can we observe (@shreyanshjn).
            //count[1] nodes got 1 unit closer to new root and n - count[1] nodes got 1 unit away from the new root.
            ans[u]=ans[node]-count[u]+n-count[u];
            dfs2(u,n,node);
        }
    }
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) 
    {
        g.resize(n);
        for(auto &e:edges)
        {
            g[e[0]].push_back(e[1]);
            g[e[1]].push_back(e[0]);
        }
        count.resize(n);
        ans.resize(n);
        dfs(0);
        dfs2(0,n);
        return ans;
        
    }
};