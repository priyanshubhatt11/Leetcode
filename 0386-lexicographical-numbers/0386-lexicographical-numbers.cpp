class Solution {
public:
    
    void solve(int i, int n, vector<int>&vec){
        if(i > n)return;
        vec.push_back(i);
        for(int j=0;j<=9;j++){
            solve(i *10 + j, n, vec);
        }
    }
    
    vector<int> lexicalOrder(int n) {
        vector<int> vec;
        for(int i=1;i<=9;i++){
            solve(i, n, vec);
        }
        return vec;
    }
};