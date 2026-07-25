// class Solution {
// public:
//     int maxProduct(int n) {
//         vector<int>arr;
//         while(n>0){
//             int digit=n%10;
//             arr.push_back(digit);
//             n/=10;
//         }
//         sort(arr.begin(),arr.end());
//         int m=arr.size();
//         return arr[m-1]*arr[m-2];
        
//     }
// };

class Solution {
public:
    int maxProduct(int n) {
        int largest = -1;
        int secondLargest = -1;

        while (n > 0) {
            int digit = n % 10;

            if (digit >= largest) {
                secondLargest = largest;
                largest = digit;
            } 
            else if (digit > secondLargest) {
                secondLargest = digit;
            }

            n /= 10;
        }

        return largest * secondLargest;
    }
};