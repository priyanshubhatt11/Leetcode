class Solution {
public:
    long long countFairPairs(vector<int>& v, int a, int b) {
        deque<int>vc;
        sort(v.begin(),v.end());
        for(auto i:v) vc.push_back(i);
        long long int ans=0;
        for(int i=0;i<v.size();i++)
        {
            vc.pop_front();
            auto it=lower_bound(vc.begin(),vc.end(),a-v[i]);
            auto it1=upper_bound(vc.begin(),vc.end(),b-v[i]);
            ans+=(it1-it);
        }
        return ans;
    }
};