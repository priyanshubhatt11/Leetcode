class Solution {
public:
    vector<int> goodIndices(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> vec1(n, 1), vec2(n, 1);
        
        for(int i=1;i<n;i++){
            if(nums[i] <= nums[i-1]){   // decreasing
                vec1[i] = 1 + vec1[i-1];
            }
        }
        for(int i= n-2;i>=0;i--){   
            if(nums[i] <= nums[i+1]){   // increasing
                vec2[i] = vec2[i+1] + 1;
            }
        }
        
        vector<int> ans;
        for(int i=k;i<n-k;i++){
            if(vec2[i+1] >= k && vec1[i-1] >= k)ans.push_back(i);
        }
        return ans;
    }
};