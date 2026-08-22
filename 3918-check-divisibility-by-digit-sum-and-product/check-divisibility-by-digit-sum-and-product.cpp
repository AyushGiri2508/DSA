// class Solution {
// public:
// int product(int n){
//     int prod=1;
//     while(n>0){
//         int bit=n%10;
//         prod*=bit;
//         n/=10;
//     }
//     return prod;
// }
// int digitsum(int n){
//     int sum=0;
//     while(n>0){
//         int bit=n%10;
//         sum+=bit;
//         n/=10;
//     }
//     return sum;
// }
//     bool checkDivisibility(int n) {
//         int val=digitsum(n)+product(n);
//         if(n%val==0)return true;

//       return false;  
//     }
// };

class Solution {
public:
    bool checkDivisibility(int n) {
        int sum = 0;
        int product = 1;
        int temp = n;

        while (temp > 0) {
            int digit = temp % 10;

            sum += digit;
            product *= digit;

            temp /= 10;
        }

        return n % (sum + product) == 0;
    }
};