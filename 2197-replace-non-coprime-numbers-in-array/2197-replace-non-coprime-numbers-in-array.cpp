class Solution {
public:
    
    int gcd(long long n, long long m){
        if(m == 0)return n;
        return gcd(m, n%m);
    }
    
    vector<int> replaceNonCoprimes(vector<int>& nums) {
        vector<int> vec;
        vec.push_back(nums[0]);
        for(int i=1;i<nums.size();i++){
            long long x = nums[i];
            while(vec.size() >0 && gcd(x, vec.back()) >1){      // __gcd do not work because size is very large
                long long y = vec.back();
                vec.pop_back();
                x = (x*y)/__gcd(x,y);
            }
            vec.push_back(x);
        }
        return vec;
    }
};