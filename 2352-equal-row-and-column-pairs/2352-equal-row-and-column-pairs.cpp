class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        map<vector<int> , int> map;
        int ans =0;
        
        for(int i=0;i<grid.size();i++){
            vector<int> vec;
            for(int j=0;j<grid[0].size();j++){
                vec.push_back(grid[i][j]);
            }
            //  for(int i:vec){
            //     cout<<i<<" ";
            // }
            // cout<<endl;
            map[vec]++;
        }
        for(int i=0;i<grid.size();i++){
            vector<int> vec;
            for(int j=0;j<grid[0].size();j++){
                vec.push_back(grid[j][i]);
            }
            // for(int i:vec){
            //     cout<<i<<" ";
            // }
            // cout<<endl;
            if(map[vec] > 0)ans += map[vec];
        }
        return ans;
    }
};