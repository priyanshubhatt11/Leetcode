class Solution {
public:
    
    void inserr(vector<char> &vec, int c){
        string s = "";
        while(c>0){
            int temp = c%10;
            s.push_back(temp+'0');
            c = c/10;
        }
        reverse(s.begin(), s.end());
        for(char i: s){
            vec.push_back(i);
        }
    }
    
    int compress(vector<char>& s) {
        if(s.size() == 1)return 1;
        int ans=0;
        vector<char> vec;
        for(int i=0;i<s.size();i++){
            int c=1;
            vec.push_back(s[i]);
            while( i < s.size()-1  && s[i] == s[i+1]){
                i++;
                c++;
            }
            //cout<<"f";
            if(c>1 && c<10){
                vec.push_back(c + '0');
            }
            else if(c >= 10){
                inserr(vec, c);
            }
        }
        
        s = vec;
        
        return vec.size();
    }
};