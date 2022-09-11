class Solution {
public:
    void solve(int index,int &ans,int n,int arr[]){
        //whenever a permutation with lenth n is made ans++ 
        // also checks number should not start with 0
        if(index==n && arr[0]!=0){
            ans++;
            return;
        }  
        
        
        //backtacking method for all permutation
        for(int i=index;i<10;i++){
            swap(arr[i],arr[index]);
            solve(index+1,ans,n,arr);
            swap(arr[i],arr[index]);
        }
    }
    
    int countNumbersWithUniqueDigits(int n) {
        int ans=0;
        
        int arr[]={0,1,2,3,4,5,6,7,8,9};
        
        //loop for all values from 0 to n
        for(int i=0;i<=n;i++)
            solve(0,ans,i,arr);
        
        ans++; // +1 for zero(0)
        return ans;
    }
};