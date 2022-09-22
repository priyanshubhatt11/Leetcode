class Solution {
public:
    
    int findgcd(int n, int m){
        while(m!=n){
            if(m>n)m=m-n;
            if(n>m)n = n-m;
        }
        return n;
    }
    
    string gcdOfStrings(string str1, string str2) {
        if(str1 + str2 != str2 + str1)return "";
        
        int n = str1.size();
        int m = str2.size();
        return str1.substr(0, findgcd(n,m));
    }
};