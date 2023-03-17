class Solution {
public:
    set<vector<vector<int>>> vis;
    int dx[5] = {1,0,-1,0, 0};
    int dy[5] = {0,1,0,-1, 0};
    vector<vector<int>> changeMat(vector<vector<int>> &vec, int i ,int j){
        vector<vector<int>> mat = vec;
        
        for(int k=0;k<5;k++){
            int r = i+dx[k];
            int c = j+dy[k];
            if(r<0 || r >=mat.size() || c<0 || c>=mat[0].size())continue;
            mat[r][c] = !mat[r][c];
        }
        return mat;
    }
    
    bool checkone(vector<vector<int>>&vec){
        for(int i=0;i<vec.size();i++){
            for(int j=0;j<vec[0].size();j++){
                if(vec[i][j] == 1)return false;
            }
        }
        return true;
    }
    
    int minFlips(vector<vector<int>>& mat) {
        queue<vector<vector<int>>> q; // matrix, count of one
        
        int n = mat.size(), m = mat[0].size();
        
        int c =0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j] == 1)c++;
            }
        }
        
        
        vis.insert(mat);
        q.push(mat);
        
        int count =0;
        while(!q.empty()){
            int k = q.size();
      
            while(k--){
                vector<vector<int>> vec = q.front();
                q.pop();
                if(checkone(vec))return count;
                
                for(int i=0;i<n;i++){
                    for(int j=0;j<m;j++){
                        
                       vector<vector<int>> vv = changeMat(vec, i, j);  
                        if(vis.count(vv) == false){
                            q.push(vv);
                            vis.insert(vv);
                        }
                    }
                }
            }
            count++;
        }
        return -1;
        
        
    }
};