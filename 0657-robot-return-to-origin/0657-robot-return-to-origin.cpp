class Solution {
public:
    bool judgeCircle(string moves) {
        int x =0, y =0;
        for(char i:moves){
            if(i == 'L')x--;
            if(i == 'R')x++;
            if(i == 'U')y--;
            if(i == 'D')y++;
        }
        if(x == 0 && y == 0)return true;
        return false;
    }
};