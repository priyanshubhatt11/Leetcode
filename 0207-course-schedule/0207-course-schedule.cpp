class Solution {
public:
    bool canFinish(int num, vector<vector<int>>& pre) {
        vector<vector<int>> adj(num);
        vector<int> ino(num, 0);
        for(auto i:pre){
            adj[i[1]].push_back(i[0]);
            ino[i[0]]++;
        }
        queue<int> q;
        for(int i=0;i<num;i++){
            if(ino[i] == 0)q.push(i);
        }
        int c=0;
        while(!q.empty()){
            int x = q.front();
            q.pop();
            c++;
            for(auto i:adj[x]){
                ino[i]--;
                if(ino[i] == 0)q.push(i);
            }
        }
        return c == num;
        
    }
};