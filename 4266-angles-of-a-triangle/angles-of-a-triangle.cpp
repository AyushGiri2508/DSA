#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;
class Solution {
public:
    vector<double> internalAngles(vector<int>& sides) {
        vector<int>side=sides;
        double a=side[0];
        double b=side[1];
        double c=side[2];

        if(a+b<=c||a+c<=b||b+c<=a){
            return {};
        }
             double pi=acos(-1.0);
            double A=acos((b*b+c*c-a*a)/(2.0*b*c))*180.0/pi;
             double B=acos((a*a+c*c-b*b)/(2.0*a*c))*180/pi;
             double C=acos((b*b+a*a-c*c)/(2.0*a*b))*180/pi;
      

        vector<double>ans={A,B,C};
        sort(ans.begin(),ans.end());
        return ans;
        
    }
};