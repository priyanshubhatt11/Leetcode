class Solution {
public:
    int xorOperation(int n, int start) {
        int ans=0;
        for(int i=0;i<n;i++){
            
            int num = start + 2*i;
            //cout<<num<<" ";
            ans = ans ^ num;
            
        }
        return ans;
    }
};