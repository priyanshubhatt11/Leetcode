class Solution {
public:
    // we can make 0 at last by finding number of factors of 2 and 5 of that number
    int maxTrailingZeros(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<pair<int,int>>> vec(n, vector<pair<int,int>>(m , {0, 0}));
        vector<vector<pair<int,int>>> left, right, up, down;
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                int two =0, five =0;
                int x = grid[i][j];
               while(x%2==0){
					x /= 2;
					two++;
				}
				while(x%5==0){
					x /= 5;
					five++;
				}
                vec[i][j] = {two, five};
            }
        }
        // for(auto i:vec){
        //     for(pair<int,int> j: i)cout<<j.first<<" "<<j.second<<"  ";
        //     cout<<endl;
        // }
            
        left = right = up = down = vec;
        for(int i=0;i<n;i++){
            for(int j=1;j<m;j++){
                right[i][j].first += right[i][j-1].first;
                right[i][j].second += right[i][j-1].second;
            }
        }
        for(int i=n-1;i>=0;i--){
            for(int j=m-2;j>=0;j--){
                left[i][j].first += left[i][j+1].first;
                left[i][j].second += left[i][j+1].second;
            }
        }
        for(int i=0;i<m;i++){ // start from top
            for(int j=1;j<n;j++){
                down[j][i].first += down[j-1][i].first;
                down[j][i].second += down[j-1][i].second;
            }
        }
        for(int i=0;i<m;i++){  // start from bottom
            for(int j=n-2;j>=0;j--){
                up[j][i].first += up[j+1][i].first;
                up[j][i].second += up[j+1][i].second;
            }
        }
        
        int ans =0;
        // checking in every block its prefix and suffix 
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                int l1 = left[i][j].first;
                int l2 = left[i][j].second;
                
                int r1 = right[i][j].first;
                int r2 = right[i][j].second;
                
                int u1 = up[i][j].first;
                int u2 = up[i][j].second;
                
                int d1 = down[i][j].first;
                int d2 = down[i][j].second;
                
                int c1 = vec[i][j].first;
                int c2 = vec[i][j].second;
                
                // ans = max(ans , min(min({l1+d1-c1 , l1+u1-c1 , r1+d1-c1 , r1+u1-c1}), min({l2+d2-c2, l2+u2-c2, r2+d2-c2, r2+u2-c2})));
                ans = max(ans , min(l1+u1-c1 , l2+u2-c2));
                ans = max(ans, min(l1+d1-c1 , l2+d2-c2));
                ans = max(ans , min(r1+u1-c1 , r2+u2-c2));
                ans = max(ans, min(r1+d1-c1 , r2+d2-c2));
                
            }
        }
        
         return ans;
        
    }
};




















