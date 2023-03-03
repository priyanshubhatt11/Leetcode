class Solution {
public:
    int strStr(string hay, string nee) {
        int j=0;
        for(int i=0;i<hay.size();i++){
            if(hay[i] == nee[0]){
                for(j=0;j<nee.size();j++){
                    if(hay[i+j] != nee[j]){
                        break;
                    }
                }
                if(j == nee.size())return i;   
            }
               
        }
        return -1;
    }
};