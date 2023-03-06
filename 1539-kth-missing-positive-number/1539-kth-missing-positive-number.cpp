class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int n=1;
        int m =0;
        while(m<arr.size() && k!=0){
            if(arr[m] == n){
                n++;
                m++;
            }
            else{
                n++;
                k--;
            }
        }
        for(int j=0;j<k;j++){
            n++;
        }
        return n-1;
        
        
    }
};