// class Solution {
// public:
// int rootval(int x){
//  int start=0;
//        int end=x;
//        int ans=0;
//        while(start<=end){
//         int mid=start+(end-start)/2;
//         if(mid*mid==x){
//             return mid;
//         }
//         else if(mid*mid>x){
//             end =mid-1;
//         }
//         else if(mid*mid<x){
//             ans=mid;
//             start=mid+1;
//         }
//        }
//        return ans;
// }
//     int mySqrt(int x) {
//       int ans=rootval(x);
//       return ans;
//     }
// };
class Solution {
public:
    int rootval(int x) {
        int start = 0;
        int end = x;
        int ans = 0;

        while (start <= end) {
            long long mid = start + (end - start) / 2;

            long long square = mid * mid;

            if (square == x) {
                return mid;
            }
            else if (square > x) {
                end = mid - 1;
            }
            else {
                ans = mid;
                start = mid + 1;
            }
        }

        return ans;
    }

    int mySqrt(int x) {
        return rootval(x);
    }
};