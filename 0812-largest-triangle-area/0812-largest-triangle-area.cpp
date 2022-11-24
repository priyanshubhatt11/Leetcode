class Solution {
public:
    double largestTriangleArea(vector<vector<int>>& points) {
        //vector<double> v;
        double mx = 0.0;
        
        int i=0;
        while(i<points.size())
        {
          int j=i+1;
          while(j<points.size())
          {
            int k=j+1;
            while(k<points.size())
            {
               //x1(y2-y3)
               double a=points[i][0]*(points[j][1]-points[k][1]);
               //x2(y3-y1)
               double b=points[j][0]*(points[k][1]-points[i][1]);
               //x3(y1-y2)
               double c=points[k][0]*(points[i][1]-points[j][1]);
               double x=0.5;
               double area=(x)*(abs(a+b+c));
               //cout<<"area: "<<area<<endl;
               mx = max(mx , area);
               k++;
            }
            j++;
          }
          i++;
        }
        // int max=*max_element(v.begin(),v.end());
         return mx;
       
    }
};