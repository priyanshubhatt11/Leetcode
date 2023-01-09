class Solution {
public:
    
    vector<int> primeF(int n){
        vector<bool> pr(n+1,true);
       
        for(long long i=2;i<=n;i++){
            for(long long j=i*i;j<=n;j+=i){
                pr[j] = false;
            }
        }
        vector<int> vec;
        for(int i=2;i<=n;i++){
            if(pr[i] == true){
                vec.push_back(i);
            }
        }
        return vec;
    }
    
    int solve(int n, vector<int>&vec){
        int ans=0;
        int i=0;
        while(n/vec[i] > 0){
            if(n%vec[i]==0){
                ans+=vec[i];
                n = n/vec[i];
            }
            else i++;
        }
        
        return ans;
    }
    int smallestValue(int n) {
        vector<int> vec = primeF(n);
        
        int x=0;
        while(true){
            int x = solve(n, vec);
            if(x == n)break;
            n=x; 
            //cout<<x<<" ";
        }
        return n;
    }
};