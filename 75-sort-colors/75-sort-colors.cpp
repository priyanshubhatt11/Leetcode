class Solution {
    class Compare{
        public:
          bool operator()(int a,int b){
              return a>b;
          }
    };
public:
    void sortColors(vector<int>& nums) {
         make_heap(nums.begin(),nums.end());
        for(int i =0; i < nums.size(); i++){
            pop_heap(nums.begin(),nums.end()-i);
        }
    }
};