class Solution {
public:
    
    void solve(int n,int k, int num, vector<int> &ans){
        if(n==0){
            ans.push_back(num);
            return;
        }
        int last = num%10;
        if(last + k < 10){
            solve(n-1 , k, num *10 + last + k, ans);
        }
        if(k!=0 && last - k > -1){
            solve(n-1, k, num*10 + last-k, ans);
        }
    }
    
    vector<int> numsSameConsecDiff(int n, int k) {
        if(n == 1){
            return {0,1,2,3,4,5,6,7,8,9};
        }
        vector<int> ans;
        for(int i=1;i<=9;i++){
            solve(n-1, k, i , ans);
        }
        return ans;
    }
};