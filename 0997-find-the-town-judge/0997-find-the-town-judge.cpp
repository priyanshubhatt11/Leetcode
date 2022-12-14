class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        // vector<vector<int>> vec(n+1);
        // vector<bool> vis(n+1, false);
        // for(auto i:trust){
        //     vec[i[1]].push_back(i[0]);
        //     vis[i[0]] = true;
        // }
        // for(int i=1;i<=n;i++){
        //     if(vec[i].size() == n-1 && vis[i] == false){
        //         return i;
        //     }
        // }
        // return -1;
        // 
        
        //          OR
        
        vector<int> vec(n+1, 0);
        for(auto i:trust){
            vec[i[0]]--;
            vec[i[1]]++;
        }
        for(int i=1;i<=n;i++) if(vec[i] == n-1)return i;
        return -1;
        
    }
};