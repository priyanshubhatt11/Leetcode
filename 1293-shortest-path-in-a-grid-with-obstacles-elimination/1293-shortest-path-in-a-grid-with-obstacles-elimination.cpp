class Solution {
public:
    int shortestPath(vector<vector<int>>& grid, int k) {
        vector<vector<int>> vis(grid.size(),vector<int>(grid[0].size(),-1));
        queue<vector<int>> q;
        
        //queue stores index x,y ,current path length and k
        q.push({0,0,0,k});
        while(!q.empty())
        {
            auto temp=q.front();
            int x=temp[0];
            int y=temp[1];
            q.pop();
            
            //checking bounds of newly pushed x and y 
             if(x<0 || y<0 || x>=grid.size() || y>=grid[0].size()){
                continue;
            }
            
            //if we reached the end return answer as length of path ( temp[2])
		    if(x==grid.size()-1 && y==grid[0].size()-1)
                return temp[2];
            
            if(grid[x][y]==1)
            {
                //k--, decrease k when obstacle found to eliminate it
                if(temp[3]>0)
                {
                    temp[3]--;
                }
                else
                {
                    continue;
                }
            }
            //we should allow an path with more optiond to eliminate obstacles for optimal answer
            //therefore if a path with less elimination option comes, we know we had a good path already at vis[x][y] so continue
            if(vis[x][y]!=-1 && vis[x][y]>=temp[3])
            {
                continue;
            }
            vis[x][y]=temp[3];
             
            //moving to next level/length->up down left and right
            q.push({x+1,y,temp[2]+1,temp[3]});
            q.push({x,y+1,temp[2]+1,temp[3]});
            q.push({x-1,y,temp[2]+1,temp[3]});
            q.push({x,y-1,temp[2]+1,temp[3]});
        }
        return -1;
    }
};
