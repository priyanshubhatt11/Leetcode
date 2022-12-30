class Solution {
public:
    vector<vector<int>> ans;
    int n;
    void solve(vector<vector<int>>&graph, vector<int> &vec, int s){
        vec.push_back(s);
        if(s == n-1){
            ans.push_back(vec);
        }
        for(auto i:graph[s]){
            solve(graph, vec, i);
        }
        vec.pop_back();
    }
    
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        n = graph.size();
        vector<int> vec;
        solve(graph, vec, 0);
        return ans;
    }
};