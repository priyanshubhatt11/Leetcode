class Solution {
public:
    string getPermutation(int n, int k) {
        string s= "";
        for(int i=1;i<=n;i++){
            s += to_string(i);
        }
        int i=0;
        string ans = "";
        do{
            ans = s;
            i++;
        }while(i!= k && next_permutation(s.begin(), s.end()));
        return ans;
    }
};