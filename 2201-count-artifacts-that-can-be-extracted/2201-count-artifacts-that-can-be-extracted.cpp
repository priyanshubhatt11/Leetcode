class Solution {
public:
    int digArtifacts(int n, vector<vector<int>>& artifacts, vector<vector<int>>& dig) {
        vector<vector<bool>> vis(n+1, vector<bool> (n+1, false));
        for(auto i:dig){
            vis[i[0]][i[1]] = true;
        }
        
        int ans= 0;
        for(auto i: artifacts){
            bool flag = true;
            for(int j= i[0] ; j<= i[2] ; j++){
                for(int k = i[1] ; k<= i[3]; k++){
                    if(vis[j][k] == false){
                        flag = false; 
                        break;
                    }
                }
            }
            if(flag)ans++;
        }
        
        return ans;
    }
};