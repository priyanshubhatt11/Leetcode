//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
//User function template for C++
class Solution{
public:

	long long maxProduct(vector<int> arr, int n) {
	    long long ans=INT_MIN, s1=1, s2=1;
	    int j = n-1;
	    for(int i=0;i<n;i++){
	        s1 *= arr[i];
	        s2 *= arr[j--];
	        ans = max(ans, max(s1,s2));
	        //cout<<s1<<" "<<s2<<" "<<ans<<endl;
	        if(s1 == 0)s1 = 1;
	        if(s2 == 0)s2 = 1;
	    }
	    return ans;
	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        vector<int> arr(n);
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.maxProduct(arr, n);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends