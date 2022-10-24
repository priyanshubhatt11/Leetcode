//  https://www.youtube.com/watch?v=MbAhaBBOmQc

// in example 1 - [1 ,1 ,3 ,3 ,3 ,5 ,2 ,2 ,2 ,2 ,2 ,2 ,2, 2, 2, 2, 2, 2, 2, 2 ]; ans then find median
class Solution {
public:
    long long minCost(vector<int>& nums, vector<int>& cost) {
        int n = nums.size();
        vector<pair<int,int>> vec;
        
        for(int i=0;i<n;i++){
            vec.push_back({nums[i], cost[i]});
        }
        sort(vec.begin(), vec.end());
        
        vector<long long> prefS(n, 0);
        prefS[0] = vec[0].second;
        for(int i=1;i<n;i++){
            prefS[i] += vec[i].second + prefS[i-1];
        }
        
        long long x = prefS[n-1]/2;   // median
        //cout<<x<<" ";
        int tar =0;
        for(int i=0;i<n;i++){
            if(prefS[i] >= x){
                tar = i;
                break;
            }
        }
        //cout<<tar<<" ";
        long long ans =0;
        for(int i=0;i<n;i++){
            ans += abs((long long)vec[i].first - vec[tar].first) * vec[i].second;
        }
        return ans;
        
    }
};










