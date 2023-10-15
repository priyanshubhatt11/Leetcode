class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        string str = "";
        string ans = "";
        int x = INT_MAX;
        for(int i=0;i<s.size();i++){
            int c =0;
            
            for(int j=i;j<s.size();j++){
                
                if(s[j] == '1'){
                    
                    c++;
                    //cout<<j<<" "<<c<<" ";
                }
                if(c>k)break;
                if(c == k){
                    int d = j-i+1;
                    if(d <= x){
                        x = d;
                        // cout<<c<<" ";
                        // cout<<j-i+1<<"\n";
                        str = s.substr(i, j-i+1);
                        //cout<<str<<" ";
                        if(ans == "" ){
                            ans = str;
                        }
                        //cout<<str<<" ";
                        ans = min(ans, str);
                        if(ans.size() > str.size()){
                            ans = str;
                        }
                    }
                }
            }
            //cout<<endl;
        }
        return ans;
    }
};