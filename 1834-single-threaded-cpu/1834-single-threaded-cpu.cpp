class Solution {
public:
    vector<int> getOrder(vector<vector<int>>& tasks) {
        for(int i=0;i<tasks.size();i++)
            tasks[i].push_back(i);
        sort(begin(tasks),end(tasks));
        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>> pq;
        vector<int> ans;
        int maxEn = 0, i=0;
        while(ans.size() < tasks.size()){
            if(i<tasks.size() && pq.empty())
                maxEn = max(maxEn,tasks[i][0]);
            while(i<tasks.size() && maxEn >= tasks[i][0]){
                pq.push({tasks[i][1],tasks[i][2]});
                i++;
            }
            auto x = pq.top();
            pq.pop();
            maxEn = min(1000000000,x[0]+maxEn);
            ans.push_back(x[1]);
        }
        return ans;
    }
};