class Solution {
public:
    int minFlips(vector<vector<int>>& mat) {
        int n = mat.size(), m= mat[0].size();
        int dx[5] = {1,0,0,-1,0};
        int dy[5] = {0,1,-1,0, 0};
        queue<vector<vector<int>>> q;
        set<vector<vector<int>>> vis;
        vis.insert(mat);
        q.push(mat);
        int c =0;
        while(!q.empty()){
            int t = q.size();
            c++;
            while(t--){
                vector<vector<int>> vv = q.front();
                q.pop();
                int x =0;
                for(int i=0;i<n;i++){
                    for(int j=0;j<m;j++){
                        if(vv[i][j] == 1){
                            x++;
                        }
                    }
                }
                
                if(x == 0)return c-1;
                
                for(int i=0;i<n;i++){
                    for(int j=0;j<m;j++){
                        vector<vector<int>> vec = vv;
                        for(int k=0;k<5;k++){
                            int rr = i+dx[k];
                            int cc = j+dy[k];
                            if(rr<0 || rr >= n || cc<0 || cc >= m )continue;
                            vec[rr][cc] = !vec[rr][cc];
                        }
                        if(vis.count(vec) == false){
                        vis.insert(vec);
                            q.push(vec);
                        }

                    }
                }
            }
        }
        return -1;
        
    }
};