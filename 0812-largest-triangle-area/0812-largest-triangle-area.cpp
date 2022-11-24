class Solution {
public:
    //  area = (1/2)* (x1(y2 - y3) + x2(y3 - y1) + x3(y1 - y2))
    
    double largestTriangleArea(vector<vector<int>>& points) {
        int n = points.size();
        double ans =0;
        for(int i=0;i<n-1;i++){
            for(int j=i+1;j<n-1;j++){
                for(int k = j+1;k<n;k++){
                    double x1 = (double)points[i][0];
                    double x2 = (double)points[j][0];
                    double x3 = (double)points[k][0];
                    double y1 = (double)points[i][1];
                    double y2 = (double)points[j][1];
                    double y3 = (double)points[k][1];
                    
                    double a = 0.5 * (x1*(y2 - y3) + x2*(y3 - y1) + x3*(y1 - y2));
                    
                    ans = max(ans , abs(a));
                    
                }
            }
        }
        return ans;
    }
};