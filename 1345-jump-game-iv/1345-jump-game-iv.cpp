class Solution {
public:
    int minJumps(vector<int>& arr) {
        unordered_map<int,vector<int>> map;
        
        for(int i=0;i<arr.size();i++){
            map[arr[i]].push_back(i);
        }
        
        int ans=0;
        int n = arr.size();
        vector<bool> vis(n, false);
        queue<int> q;
        q.push(0);
        
        while(!q.empty()){
            int k = q.size();
            while(k--){
                
                int idx = q.front();
                q.pop();
                if(idx == n-1)return ans;
                
                vector<int> vec;
                vec = map[arr[idx]];  
                map.erase(arr[idx]);
                vec.push_back(idx+1);
                vec.push_back(idx-1);
                
                for(int i:vec){
                    if(i<0 || i>=n || vis[i] == true)continue;
                    
                    vis[i] = true;
                    q.push(i);
                }
            }
            ans++;
        }
        
        return ans;
        
    }
};