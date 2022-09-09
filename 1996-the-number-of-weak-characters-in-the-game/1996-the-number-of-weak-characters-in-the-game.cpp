class Solution {
public:
    
    static bool compare(vector<int> &A, vector<int> &B){
        if(A[0] == B[0]) return A[1] < B[1];
        return A[0] > B[0];
    }
    
    int numberOfWeakCharacters(vector<vector<int>>& pro) {
        sort(pro.begin(), pro.end(), compare);
       
        int ans =0,mm = pro[0][1];
        for(auto i:pro){
            for(int j:i){
                cout<<j<<" ";
            }
            cout<<endl;
        }
        for(int i=1;i<pro.size();i++){
            //cout<<mm;
            
            if(pro[i][1] < mm){
                
                ans++;
            }
            mm = max(mm, pro[i][1]);
        }
        
        return ans;
    }
};