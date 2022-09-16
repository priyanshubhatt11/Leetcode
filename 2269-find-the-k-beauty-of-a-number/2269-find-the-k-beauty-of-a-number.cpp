class Solution {
public:
    int divisorSubstrings(int num, int k) {
        string str = to_string(num);

        int ans=0;
        
        for(int i=0;i<=str.size()-k;i++){
            int x = stoi(str.substr(i,k));
            if(x!=0 && num%x == 0){
                ans++;
            }
        }
        return ans;
    }
};