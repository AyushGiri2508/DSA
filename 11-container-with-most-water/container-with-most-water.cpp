class Solution {
public:
    int maxArea(vector<int>& height) {
        int n=height.size();
        int i=0;
        int j=n-1;
        int area=0;
        int maxi=INT_MIN;
        while(i<j){
            int breadth= min(height[i],height[j]);
            area=breadth*(j-i);
            maxi=max(area,maxi);
            if(height[i]>height[j]){
                j--;
            }
            else{
                i++;
            }
        }
        return maxi;
    }
};