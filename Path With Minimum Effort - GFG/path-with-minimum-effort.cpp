//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    
    int dx[4] = {1,-1,0,0};
    int dy[4] = {0,0,1,-1};
    int MinimumEffort(vector<vector<int>>& nums) {
        int n = nums.size(), m = nums[0].size();
        vector<vector<int>> dist(n, vector<int> (m, INT_MAX));
        dist[0][0] = 0;
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        pq.push({0, 0, 0});
        
        while(!pq.empty()){
            vector<int> temp = pq.top();
            pq.pop();
            int i = temp[1], j = temp[2], diff = temp[0];
            
            if(i == n-1 && j == m-1)return temp[0];
            
            //cout<<i<<" "<<j<<" | ";
            for(int k=0;k<4;k++){
                int r = i+dx[k];
                int c = j+dy[k];
               
                if(r>=0 && c>=0 && r<n && c<m){
                    
                    
                    int mx = max(diff , abs(nums[i][j] - nums[r][c]));
                    if(dist[r][c] > mx){
                        dist[r][c] = mx;
                        pq.push({mx, r, c});
                    }
                }
            }
            
        }
        // for(auto i:dist){
        //     for(auto j:i)cout<<j<<" ";
        //     cout<<endl;
        // }
         return 0;
        
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n,m; cin>>n>>m;
        vector<vector<int>> heights;
       
        for(int i=0; i<n; ++i){
            vector<int> temp;
            for(int j=0; j<m; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            heights.push_back(temp);
        }
       
        Solution obj;
        cout<<obj.MinimumEffort(heights)<<"\n";
    }
    return 0;
}
// } Driver Code Ends