class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        priority_queue<int> q;
        for(int i:piles){
            q.push(i);
        }
        while(k--){
            int x = q.top();
            q.pop();
            x = ceil(x/2.0);
            q.push(x);
        }
       
        int ans=0;
        
        while(!q.empty()){
            int x = q.top();
            q.pop();
            ans+=x;
        }
        return ans;
    }
};