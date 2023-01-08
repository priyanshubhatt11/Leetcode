class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        
        int maxLines = 0; 
        double slope = 0;


        for(auto point1: points) {

            unordered_map<double, int> slopeCounter;

            for(auto point2: points) {

                slope = 0;

                if(point1[0] == point2[0] && point1[1] == point2[1]) continue; // for same point 

                // if x-coordinates are same then slope becomes infinity
                if(point2[0] == point1[0]) {
                    slope = INT_MAX;
                }
                else{
                    // m = (y2 - y1) / (x2 - x1)
                    slope = (point2[1] - point1[1]) / double(point2[0] - point1[0]);
                }
                slopeCounter[slope]++;
                maxLines = max(slopeCounter[slope], maxLines);
            }

        }

        return maxLines + 1;
    }
};