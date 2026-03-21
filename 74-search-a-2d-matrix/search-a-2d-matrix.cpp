class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int start=0;
        int row=matrix.size();
        int col=matrix[0].size();
        int size=row*col;
        int end=size-1;
        int mid=start+(end-start)/2;
        while(start<=end){
            int r=mid/col;
            int c=mid%col;
            if(matrix[r][c]==target){
                return true;
            }
             else if(matrix[r][c]<target){
                start=mid+1;
             }
             else{
                end=mid-1;
             }
             mid=start+(end-start)/2;
        }
       return false; 
    }
};