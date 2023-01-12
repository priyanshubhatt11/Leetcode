//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    
    void solve(vector<vector<int>>&vec, vector<vector<bool>>&vis, int i, int j, int old, int nn){
        if(i<0 || i>=vec.size() || j<0 || j>=vec[0].size() || vis[i][j] || vec[i][j] != old)return;
        vec[i][j] = nn;
        vis[i][j] = true;
        solve(vec, vis, i+1, j, old, nn);
        solve(vec, vis, i, j+1, old, nn);
        solve(vec, vis, i-1, j, old, nn);
        solve(vec, vis, i, j-1, old, nn);
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int n = image.size(), m = image[0].size();
        vector<vector<bool>>vis(n, vector<bool> (m,false));
        int old = image[sr][sc];
        solve(image, vis, sr,sc, old, newColor);
        return image;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>image(n, vector<int>(m,0));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++)
				cin >> image[i][j];
		}
		int sr, sc, newColor;
		cin >> sr >> sc >> newColor;
		Solution obj;
		vector<vector<int>> ans = obj.floodFill(image, sr, sc, newColor);
		for(auto i: ans){
			for(auto j: i)
				cout << j << " ";
			cout << "\n";
		}
	}
	return 0;
}
// } Driver Code Ends