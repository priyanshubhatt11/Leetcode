class Solution {
public:
    
    void solve(vector<vector<int>> &mat, int n, int m, int i, int j, int &c){
        if(i<0 || i>=n || j < 0|| j>=m)return;
        if(mat[i][j] == 1)c++;
    }
    
    void gameOfLife(vector<vector<int>>& mat) {
        int n = mat.size(), m = mat[0].size();
        vector<vector<int>> vec = mat;
        int nei =0;  // neighbour
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                nei =0;
                solve(mat, n, m , i+1, j, nei);
                solve(mat, n, m , i, j+1, nei);
                solve(mat, n, m , i-1, j, nei);
                solve(mat, n, m , i, j-1, nei);
                solve(mat, n, m , i+1, j+1, nei);
                solve(mat, n, m , i+1, j-1, nei);
                solve(mat, n, m , i-1, j+1, nei);
                solve(mat, n, m , i-1, j-1, nei);
                
                //cout<<nei<<" ";
                if(nei < 2)vec[i][j] = 0;
                else if(nei > 3)vec[i][j] = 0;
                else if(nei == 3)vec[i][j] = 1;
                
            }
            //cout<<endl;
        }
        
        mat = vec;
    }
};