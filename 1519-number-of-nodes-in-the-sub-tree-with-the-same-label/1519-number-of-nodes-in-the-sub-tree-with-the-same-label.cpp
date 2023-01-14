class Solution {
public:
    
    vector<int> dfs(vector<vector<int>>&vec, string &str, int s, int p, vector<int>&ans){
        vector<int> cnt(27,0);
        for(auto i:vec[s]){
            if(i == p)continue;
            vector<int> temp = dfs(vec, str, i, s, ans);
            for(int j=0;j<27;j++){
                cnt[j] += temp[j]; 
            }
        }
        cnt[str[s]-'a']++;
        ans[s] = cnt[str[s] - 'a'];
        return cnt;
    }
    
    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) {
        vector<vector<int>> vec(n);
        for(auto i:edges){
            vec[i[0]].push_back(i[1]);
            vec[i[1]].push_back(i[0]);
        }
        vector<int> ans(n);
        
        dfs(vec, labels, 0 ,-1, ans);
        return ans;
    }
};