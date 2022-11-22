class Solution {
public:
   // int maxNonOverlapping(vector<int>& nums, int target) {
   //      unordered_map<int,int> map;
   //      map[0] = 1;
   //      int ans =0;
   //      int sum =0;
   //      for(int i=0;i<nums.size();i++){
   //          sum += nums[i];
   //          if(map.find(sum - target) != map.end()){
   //              ans++;
   //              sum =0;
   //              map.clear();
   //          }
   //          //cout<<sum<<" ";
   //          map[sum] = 1;
   //      }
   //      return ans;
   //  }
    int maxNonOverlapping(vector<int>& nums, int target) {
        unordered_set<int> set;
        set.insert(0);
        int ans =0, sum =0;
        for(int i=0;i<nums.size();i++){
            sum += nums[i];
            if(set.count(sum - target)){
                ans++;
                sum =0;
                set.clear();
            }
            set.insert(sum);
        }
        
        return ans;
    }
    
};











