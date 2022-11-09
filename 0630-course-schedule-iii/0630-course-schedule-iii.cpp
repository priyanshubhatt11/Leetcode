class Solution {
public:
    
    bool static comp(vector<int> &A, vector<int> &B){
        return A[1] < B[1];
    }
    
    int scheduleCourse(vector<vector<int>>& nums) {
        sort(nums.begin(), nums.end(), comp);
        
        priority_queue<int> pq;
        int sum =0;
        for(auto i: nums){
            sum += i[0];
            pq.push(i[0]);
            if(sum > i[1]){
                sum -= pq.top();
                pq.pop();
            }
        }
        return pq.size();
    }
};