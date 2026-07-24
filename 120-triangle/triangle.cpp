// class Solution {
// public:

// int minimum(vector<int>v){
    
//     int mini = *min_element(v.begin(), v.end());
//     return mini;
// }
// int solve(vector<vector<int>>& triangle){
//         int n=triangle.size();
//         int m=triangle[0].size();
//         int ans=0;
//         for(int i=0;i<n;i++){
//             int val=minimum(triangle[i]);
//          ans+=val;
//         }
//         return ans;
// }
//     int minimumTotal(vector<vector<int>>& triangle) {
//         int ans=solve(triangle);
//         return ans;
        
//     }
// };



// class Solution {
// public:
//     int solve(int i, int j, vector<vector<int>>& triangle,
//               vector<vector<int>>& dp) {

//         if (i == triangle.size() - 1)
//             return triangle[i][j];

//         if (dp[i][j] != -1)
//             return dp[i][j];

//         int down = triangle[i][j] + solve(i + 1, j, triangle, dp);
//         int diag = triangle[i][j] + solve(i + 1, j + 1, triangle, dp);

//         return dp[i][j] = min(down, diag);
//     }

//     int minimumTotal(vector<vector<int>>& triangle) {
//         int n = triangle.size();
//         vector<vector<int>> dp(n, vector<int>(n, -1));

//         return solve(0, 0, triangle, dp);
//     }
// };



class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();

        vector<int> dp = triangle[n - 1];

        for (int i = n - 2; i >= 0; i--) {
            for (int j = 0; j <= i; j++) {
                dp[j] = triangle[i][j] + min(dp[j], dp[j + 1]);
            }
        }

        return dp[0];
    }
};