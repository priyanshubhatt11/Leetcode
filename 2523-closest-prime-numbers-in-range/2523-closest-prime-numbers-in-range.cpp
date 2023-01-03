class Solution {
public:
    
    vector<int> seive(int m, int n){
        vector<bool> vis(n+1, false);
        vector<int> vec;
        vis[0] = true;
        vis[1] = true;
        for(long long i=2;i<=n;i++){
            if(i*i<=n && vis[i] == false){
                for(long long j=i*i;j<=n;j+=i){
                    vis[j] = true;
                }
            }
        }
        for(int i=m;i<=n;i++){
            if(vis[i] == false){
                
                vec.push_back(i);
            }
        }
        return vec;
    }
    
    vector<int> closestPrimes(int left, int right) {
        vector<int> vec = seive(left, right);
        vector<int> ans;
        int x,y;
        if(vec.size() <2)return {-1,-1};
        int mi = INT_MAX;
        for(int i=0;i<vec.size()-1;i++){
            int diff = vec[i+1] - vec[i];
            if(diff < mi){
                x = vec[i];
                y = vec[i+1];
                mi = diff;
            }
            //cout<<diff<<" ";
        }
        
        return {x,y};
    }
};