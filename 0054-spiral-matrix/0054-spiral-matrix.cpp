class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& mat) {
        int c=0;
        int num=0;
        int n = mat.size(), m= mat[0].size();
        int tot = n*m;
        vector<int> vec;
        while(true){
            for(int i=c;i<m-c;i++){
                //cout<<c<<" "<<i<<"\n";
                vec.push_back(mat[c][i]);
                num++;
            }
            if(num>=tot)return vec;
            
            //cout<<"d\n";
            for(int i=c+1;i<n-c;i++){
                //cout<<i<<" "<<m-c-1<<"\n";
                vec.push_back(mat[i][m-c-1]);
                num++;
            }
            if(num>=tot)return vec;
            //cout<<"d\n";
            for(int i=m-c-2;i>=c;i--){
                //cout<<n-c-1<<" "<<i<<"\n";
                vec.push_back(mat[n-c-1][i]);
                num++;
            }
            if(num>=tot)return vec;
            //cout<<"d\n";
            for(int i=n-c-2;i>c;i--){
                //cout<<i<<" "<<c<<"\n";
                vec.push_back(mat[i][c]);
                num++;
            }
            if(num>=tot)return vec;
            //cout<<"d\n";
            c++;
        }
        return vec;
    }
};