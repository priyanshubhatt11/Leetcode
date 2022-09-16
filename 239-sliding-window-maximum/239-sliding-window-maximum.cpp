class Solution {
public:
    vector<int> ans;
    void solve(vector<int> &nums, int k){
        int n = nums.size();
        deque<int> q(k);
        
        for(int i=0;i<k;i++){   // we have to do this otherwise first two iteration of behind loop                                          will store two value without checking k.
            while(!q.empty() && nums[i] >= nums[q.back()]){
                q.pop_back();
            }
            q.push_back(i);
        }
        int i;
        for(int i=k;i<n;i++){
            ans.push_back(nums[q.front()]);
            while(!q.empty() && (nums[i] >= nums[q.back()])){
                q.pop_back();
            }
            while(!q.empty() && q.front() <= i-k){   // deleting when size is greater than k
                q.pop_front();
            }
            q.push_back(i);
        }
        ans.push_back(nums[q.front()]);
        
        
    }
    
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        solve(nums, k);
        return ans;
    }
};