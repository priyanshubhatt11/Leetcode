class Solution {
public:
    int countDistinct(vector<int>& nums, int k, int p) {
        set<vector<int>> set;
        int c =0;
        for(int i=0;i<nums.size();i++){
            vector<int> vec;
            c=0;
            for(int j=i;j<nums.size();j++){
                if(nums[j]%p == 0){
                    c++;
                }
                vec.push_back(nums[j]);
                if(c>k)break;
                set.insert(vec);
            }
        }   
        return set.size();
    }
};