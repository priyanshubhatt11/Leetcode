class Solution {
public:
    
    void convert(vector<vector<int>> &mat, int i, int j, int n, int m){
        int row = i;
        int col = j;
        
        while(j>=0 ){   // left
            mat[i][j] = 0;
            j--;
        }
        i=row;
        j=col;
        while(j< m){    //right
            mat[i][j] = 0;
            j++;
        }
        i=row;
        j=col;
        while(i>=0 ){   // top
            mat[i][j] = 0;
            i--;
        }
        i=row;
        j=col;
        while(i <n){
            mat[i][j] = 0;
            i++;
        }
    }
    
    void setZeroes(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        queue<pair<int ,int>> q;
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j] == 0){
                    q.push({i,j});
                    
                    
                }
            }
        }
        
        while(!q.empty()){
            auto ans = q.front();
            q.pop();
            //cout<<ans.first<<" "<<ans.second<<endl;
            convert(mat, ans.first, ans.second, n,m);
        }
    }
};