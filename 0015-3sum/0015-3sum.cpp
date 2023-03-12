class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        
        int n = nums.size();
        vector<vector<int>> vec;
        set<vector<int>> st;
        sort(nums.begin(), nums.end());
        for(int i=0;i<n;i++){
            int x = nums[i];
            int l = i+1, h = n-1;
            while(l<h){
                int y = nums[l] + nums[h];
                if(x + y == 0){
                    
                    st.insert({x,nums[l],nums[h]});
                    l++;
                }
                else if(x+y > 0)h--;
                else l++;
            }
        }
        for(auto i:st){
            vec.push_back(i);
        }
        

        return vec;
    }
};