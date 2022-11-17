class Solution {
public:
    //    27 + 24 = 51 - 6 = 45
    
    int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2) {
        
        long long l1 = abs(ax2 - ax1);
        long long b1 = abs(ay2 - ay1);
        long long l2 = abs(bx2 - bx1);
        long long b2 = abs(by2 - by1);
        
        // overlapping
        
        int left = max(ax1, bx1);
        int right = min(ax2, bx2);
        int top = min(ay2, by2);
        int bottom = max(ay1 , by1);
        
        long long over = abs((right - left) * (top - bottom));
        
        if(right > left && top > bottom){
            return (l1*b1) + (l2*b2) - over;
        }
        
        return (l1*b1) + (l2*b2) ;
        
    }
};  