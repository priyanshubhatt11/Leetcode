class Solution {
public:
    
    bool static comp(pair<int,int>&A, pair<int,int>&B){
        if(A.first != B.first)return A.first < B.first;
        return A.second < B.second;
    }
    
    int sumDigit(int n){
        int sum =0;
        while(n>0){
            int temp = n%10;
            sum += temp;
            n = n/10;
        }
        return sum;
    }
    
    int maximumSum(vector<int>& nums) {
        int n = nums.size();
        vector<int> vec(n);
        for(int i=0;i<n;i++){
            vec[i] = sumDigit(nums[i]);
            //cout<<vec[i]<<" ";
        }
        //cout<<endl;
        vector<pair<int, int>> vv;
        
        for(int i=0;i<n;i++){
            vv.push_back({vec[i], nums[i]});
        }
        sort(vv.begin(), vv.end(), comp);
        
        int ans = -1;
        for(int i=0;i<n-1;i++){
            if(vv[i].first == vv[i+1].first){
                ans = max(ans, vv[i].second + vv[i+1].second);
            }
        }
        return ans;
        
    }
};








