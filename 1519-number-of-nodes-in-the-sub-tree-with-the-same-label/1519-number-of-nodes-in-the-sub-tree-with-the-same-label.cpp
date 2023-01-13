class Solution {
public:
    vector<int>ans;
    vector<int> solve(vector<vector<int>>&adj, int start, int parent, string &labels)
    {
        vector<int>cnt(26,0);
        vector<int>temp;
        for(auto x:adj[start])
        {
            if(x==parent)
            continue;
            temp.clear();
            temp= solve(adj, x, start, labels);
            for(int i=0;i<26;i++)
            cnt[i]+=temp[i];
        }
        cnt[labels[start]-'a']++;
        ans[start]=cnt[labels[start]-'a'];
        return cnt;
    }
    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) {
        vector<vector<int>>adj(n);
        for(auto x:edges)
        {
            adj[x[0]].push_back(x[1]);
            adj[x[1]].push_back(x[0]);
        }
        ans.resize(n,0);
        solve(adj, 0, -1, labels);
        return ans;   
    }
};