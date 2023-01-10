class Solution {
public:
    // sum of set bit of two number is equal to sum of or and and of that two number
    
    int countbit(int n, long long int &ans, int k){
        int c=0;
        while(n!=0){
            n = n& (n-1);
            c++;
        }
        if(c*2>=k)ans++;
        return c;
    }
    
    long long countExcellentPairs(vector<int>& nums, int k) {
        set<int> st(nums.begin(), nums.end());
        long long ans=0;
        vector<int> vec;
        for(auto &i:st){
            vec.push_back(countbit(i,ans,k));   // count set bits
        }
        sort(vec.begin(), vec.end());
        int i=0,j=vec.size()-1;
        
        while(i<=j){
            if(vec[i] + vec[j] >= k){
                ans += 2*(j-i);
                j--;
            }
            else i++;
        }
        return ans;
    }
};