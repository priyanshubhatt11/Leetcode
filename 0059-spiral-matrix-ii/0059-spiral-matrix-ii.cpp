class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        int c=0;
        int num=1;
        int m = n;
        int tot = n*m + 1;
        vector<vector<int>> vec(n,vector<int>(n));
        while(true){
            for(int i=c;i<m-c;i++){
                //cout<<c<<" "<<i<<"\n";
                vec[c][i] = num;
                num++;
            }
            if(num>=tot)return vec;
            
            //cout<<"d\n";
            for(int i=c+1;i<n-c;i++){
                //cout<<i<<" "<<m-c-1<<"\n";
                vec[i][m-c-1]= num;
                num++;
            }
            if(num>=tot)return vec;
            //cout<<"d\n";
            for(int i=m-c-2;i>=c;i--){
                //cout<<n-c-1<<" "<<i<<"\n";
                vec[n-c-1][i]= num;
                num++;
            }
            if(num>=tot)return vec;
            //cout<<"d\n";
            for(int i=n-c-2;i>c;i--){
                //cout<<i<<" "<<c<<"\n";
                vec[i][c] = num;
                num++;
            }
            if(num>=tot)return vec;
            //cout<<"d\n";
            c++;
        }
        return vec;
    
    }
};