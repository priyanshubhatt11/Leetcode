class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        // TLE
        // int ans =left;
        // for(int i=left;i<=right;i++){
        //     ans &=i ;
        // }
        // return ans;
        
        int c=0;
        while(left!= right){
            left = left>>1;
            right = right>>1;
            c++;
        }
        return left<<c;
    }
};