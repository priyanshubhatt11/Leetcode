class Solution {
public:
    
    vector<int> solve(vector<vector<int>>&vec, string &str, vector<int> &ans, int idx, int par){
        vector<int> cnt(27 ,0);
        for(auto i:vec[idx]){
            if(par == i)continue;
            vector<int> temp = solve(vec, str, ans, i, idx);
            for(int i=0;i<27;i++){
                cnt[i] += temp[i];
            }
        }
        cnt[str[idx]-'a']++;
        ans[idx] = cnt[str[idx]-'a'];
        return cnt;
        
    }
    
    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) {
        vector<vector<int>> vec(n);
        for(auto i:edges){
            vec[i[0]].push_back(i[1]);
            vec[i[1]].push_back(i[0]);
        }
        vector<int>ans(n);
        solve(vec, labels, ans ,0, -1);
        return ans;
    }
};