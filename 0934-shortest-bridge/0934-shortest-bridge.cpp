class Solution {
public:
int vis[101][101];
bool main_flag;
bool is_valid(vector<vector<int>>& grid,int row,int col)
{
    
    if(row<0||col<0||row>=grid.size()||col>=grid.size()||grid[row][col]==1)
    return false;
    
    return true;
}
void dfs(vector<vector<int>>& grid,int i,int j)
{
    if(i<0||j<0||i>=grid.size()||j>=grid.size()||vis[i][j]==1||grid[i][j]==0)
    return;
    vis[i][j]=1;
    grid[i][j]=2;
      dfs(grid,i+1,j);
      dfs(grid,i,j+1);
      dfs(grid,i,j-1);
      dfs(grid,i-1,j);
}
    int shortestBridge(vector<vector<int>>& grid) {
        bool flag1=false;
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid.size();j++)
            {
                if(grid[i][j]==1)
                {
                 dfs(grid,i,j);
                 flag1=true;
                 break;
                }
            }
            if(flag1)
            break;
        }
        
        queue<pair<int,int>>qp;
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid.size();j++)
            {
                if(grid[i][j]==1)
                qp.push({i,j});
            }
        }
        int ans=0;
        int a[4]={1,0,0,-1};
        int b[4]={0,1,-1,0};
        while(qp.size()>0)
        {
            ans++;
            int len=qp.size();
            for(int i=0;i<len;i++)
            {
                int row=qp.front().first;
                int col=qp.front().second;
                qp.pop();
                for(int i=0;i<4;i++)
                {
                    int r = row + a[i];
                    int c = col + b[i];
                    if(is_valid(grid,r,c))
                    {
                        if(grid[r][c]==2)
                          return ans-1;
                        qp.push({row+a[i],col+b[i]});
                        grid[row+a[i]][col+b[i]]=1;
                    }   
                }
            }
            
        }
        return ans;
    }
};