class Solution {
public:
    int minimumRecolors(string b, int k) {
        int n = b.size();
        string s = b;
        int c = 0;
        int mm =1000;
        for(int i=0;i<=n-k;i++){
            //s = b;
            c=0;
            for(int j=i;j<k+i;j++){
                if(b[j] == 'W'){
                    //b[j] = 'B';
                    c++;
                }
            }
            mm = min(mm, c);
        }
        return mm;
    }
};