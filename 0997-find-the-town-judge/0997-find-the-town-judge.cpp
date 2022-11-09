class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<vector<int>> vec(n+1);
        vector<bool> vis(n+1, false);
        for(auto i:trust){
            vec[i[1]].push_back(i[0]);
            vis[i[0]] = true;
        }
        for(int i=1;i<=n;i++){
            if(vec[i].size() == n-1 && vis[i] == false){
                return i;
            }
        }
        return -1;
    }
};