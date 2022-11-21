class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& e) {
        
        queue<pair<int,int>> q;
        int n = maze.size();
        int m = maze[0].size();
        q.push({e[0], e[1]});
        int ans= 0;
        vector<vector<bool>> vis(n, vector<bool> (m,false));
        
        while(!q.empty()){
            int k = q.size();
          
            
            while(k--){
                  auto xx = q.front();
                q.pop();
                int x = xx.first, y = xx.second;
                if(x>= n || x < 0 || y >=m || y<0 || maze[x][y] == '+' || vis[x][y])continue;
                if(x == 0 || x == n-1 || y== 0 || y == m-1) {
                    if(x != e[0] || y != e[1]) return ans;
                }
                //cout<<x<<" "<<y<<endl;
                vis[x][y] = true;
                q.push({x+1, y});
                q.push({x,y+1});
                q.push({x-1, y});
                q.push({x, y-1});
            }
            ans++;
        }
        return -1;
    }
};