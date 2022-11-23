class Solution {
public:
    int nthUglyNumber(int n) {
        set<long long> set;
        long long ans =0;
        set.insert(1);
        for(int i=1;i<=n;i++){
            ans = *set.begin();
            set.erase(ans);
            set.insert(ans*2);
            set.insert(ans*3);
            set.insert(ans*5);
        }
        return ans;
    }
};