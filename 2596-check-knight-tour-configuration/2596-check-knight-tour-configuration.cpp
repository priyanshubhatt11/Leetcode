class Solution {
public:
    bool checkValidGrid(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        
        int count=0;
        int dx[8] = { 2, 1, -1, -2, -2, -1, 1, 2 };
        int dy[8] = { 1, 2, 2, 1, -1, -2, -2, -1 };
        int r = 0,c=0;
        for(int i=0;i<n*m-1;i++){
            bool flag = false;
            for(int k=0;k<8;k++){
                int g = r + dx[k];
                int h = c+ dy[k];
                if(g<0 || h< 0 || g>=n || h>=m)continue;
                //cout<<g<<" "<<h<<endl;
                if(grid[g][h] == count+1){
                    flag = true;
                    count++;
                    r = g;
                    c = h;
                    break;
                }
            }
            if(!flag){
                return false;
            }
        }
        return true;
    }
};