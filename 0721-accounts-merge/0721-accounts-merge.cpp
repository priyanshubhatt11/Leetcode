
class DisjointSet{
    public:
    vector<int> parent, rank;
   
    DisjointSet(int n){
        parent.resize(n+1);
        rank.resize(n+1, 0);
        for(int i=0;i<=n;i++){
            parent[i] = i;
        }
    }

    int findParent(int node){
        if(parent[node] == node)return node;
        return parent[node] = findParent(parent[node]);
    }

    void unionByRank(int u, int v){
        u = findParent(u);
        v = findParent(v);
        if(u == v)return;
        if(rank[u] > rank[v]) parent[v] = u;
        else if(rank[u] < rank[v]) parent[u] = v;
        else{
            parent[u] = v;
            rank[v]++;
        }
    }
};

class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& nums) {
        int n = nums.size();
        unordered_map<string, int> mp;
        DisjointSet ds(n);
        for(int i=0;i<n;i++){
            for(int j=1;j<nums[i].size();j++){
                if(mp.count(nums[i][j])){
                    ds.unionByRank(i, mp[nums[i][j]]);
                }
                else{
                    mp[nums[i][j]] = i;
                }
            }
        }
        
        vector<vector<string>> vec(n);
        for(auto i:mp){
            int x = ds.findParent(i.second);
            vec[x].push_back(i.first);
        }
        
        vector<vector<string>> ans;
        for(int i=0;i<n;i++){
            if(vec[i].size() == 0)continue;
            vector<string> vv;
            string temp = nums[i][0];
            sort(vec[i].begin(), vec[i].end());
            vv.push_back(temp);
            for(auto &j:vec[i])vv.push_back(j);
            ans.push_back(vv);
        }
        return ans;
        
    }
};


















