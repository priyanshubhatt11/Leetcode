class Solution {
public:
    vector<long long> distance(vector<int>& nums) {
        vector<pair<long long,long long>> vec;
        
        int n = nums.size();
        vector<long long> ans(n, 0);
        for(int i=0;i<n;i++)vec.push_back({nums[i], i});
        sort(vec.begin(), vec.end());
        
        for(int i=0;i<n-1;i++){
            int j = i;
            if(vec[i].first == vec[i+1].first){
                vector<long long> pref;
                pref.push_back(vec[i].second);
                while(i<n-1 && vec[i].first == vec[i+1].first){
                    pref.push_back(pref.back() + vec[i+1].second);
                    i++;
                }
                long long m = pref.size();
                for(long long k=0;k<m;k++){
                    long long x;
                    int idx = vec[k+j].second;
                    if(k == 0){
                        x = pref[m-1] - (m)*idx;
                    }
                    else if(k == m-1){
                        x = (m-1)*idx - pref[m-2];
                    }
                    else{
                        
                        x = (k)*idx - pref[k-1];
                        //cout<<x<<" ";
                        x += (pref[m-1] - pref[k]) - (m-k-1)*idx ; 
                        //cout<<m<<k<<" "<<idx<<"\n";
                    }
                    ans[idx] = x;
                   
                }
                
            }
        }
        return ans;
    }
};