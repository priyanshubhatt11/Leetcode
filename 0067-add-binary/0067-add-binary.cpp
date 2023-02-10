class Solution {
public:
    string addBinary(string a, string b) {
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());
        string s = "";
        int i=0;
        bool flag = false;
        while(i<a.size() && i<b.size()){
            if(a[i] == '0' && b[i] == '0'){
                if(flag){
                    s.push_back('1');
                    flag = false;
                }
                else
                    s.push_back('0');
            }
            else if(a[i] == '1' && b[i] == '1'){
                if(flag){
                    s.push_back('1');
                }
                else{
                    flag = true;
                    s.push_back('0');
                }
                
            }
            else{
                if(flag){
                    s.push_back('0');
                }
                else{
                    s.push_back('1');
                }
            }
            i++;
        }
        
        while(i<a.size()){
            if(a[i] == '1'){
                if(flag){
                    s.push_back('0');
                }
                else {
                    s.push_back('1');
                }
            }
            else{
                if(flag){
                    s.push_back('1');
                    flag = false;
                }
                else s.push_back('0');
            }
            i++;
        }
        while(i<b.size()){
            if(b[i] == '1'){
                if(flag){
                    s.push_back('0');
                }
                else {
                    s.push_back('1');
                }
            }
            else{
                if(flag){
                    s.push_back('1');
                    flag = false;
                }
                else s.push_back('0');
            }
            i++;
        }
        if(flag)s.push_back('1');
        reverse(s.begin(), s.end());
        return s;
        
    }
};