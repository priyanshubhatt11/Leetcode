class Solution {
public:
    long long findScore(vector<int>& nums) {
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        for(auto i=0;i<nums.size();i++)pq.push({nums[i], i});
        
        long long ans =0;
        while(!pq.empty()){
            long long x = pq.top().first;
            int idx = pq.top().second;
            pq.pop();
            
            if(nums[idx] == -1)continue;
            ans += x;
            //cout<<idx<<" ";
            if(idx-1>=0){
                nums[idx-1] = -1;
            }
            if(idx+1 < nums.size()) {
                nums[idx+1] = -1;
            }
        }
        return ans;
        
    }
};