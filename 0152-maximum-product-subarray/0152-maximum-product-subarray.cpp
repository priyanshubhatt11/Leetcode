class Solution {
public:
    int maxProduct(vector<int>& nums) {
     //the algo is extension of kadane here maintain 2 element min and max..and we get our ans
        int res=*max_element(nums.begin(),nums.end());
         int max_elem=1;
        int min_elem=1;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]==0)
            {
                max_elem=1;
                min_elem=1;
            }
            int temp=max_elem*nums[i];
            max_elem=max({temp,nums[i],min_elem*nums[i]});
            min_elem=min({temp,nums[i],min_elem*nums[i]});
           res=max(res,max_elem);
        }
        return res;
    }
};