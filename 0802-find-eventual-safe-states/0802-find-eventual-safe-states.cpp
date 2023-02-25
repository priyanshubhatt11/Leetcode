class Solution {
public:
    //https://www.youtube.com/watch?v=2gtg3VsDGyc&list=PLgUwDviBIf0oE3gA41TKO2H5bHpPd7fzn&index=26
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        // topological sort will not take cycle 
        //reversing edges
        int n = graph.size();
        vector<int> vec[n];
        vector<int> ino(n, 0);
        for(int i=0;i<graph.size();i++){
            for(auto j:graph[i]){
                vec[j].push_back(i);
                ino[i]++;
            }
        }
        queue<int> q;
        for(int i=0;i<n;i++){
            if(ino[i] == 0)
                q.push(i);
        }
        
        vector<int> ans;
        while(!q.empty()){
            int x = q.front();
            q.pop();
            ans.push_back(x);
            for(auto i:vec[x]){
                ino[i]--;
                if(ino[i] == 0){
                    q.push(i);
                }
            }
        }
        sort(ans.begin(), ans.end());
        return ans;
        
        
        
    }
};