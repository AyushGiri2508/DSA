// class Solution {
// public:
// int solve(int n,int i){
//     int ans=0;
//     if(i>n){
//         return 0;
//     }

// }
//     int rotatedDigits(int n) {
//         int ans=solve(int n,0);
//         return ans;
        
//     }
// };
class Solution {
public:
    bool isGood(int num) {
        bool changed = false;

        while (num > 0) {
            int d = num % 10;

            if (d == 3 || d == 4 || d == 7) return false;
            if (d == 2 || d == 5 || d == 6 || d == 9)
                changed = true;

            num /= 10;
        }

        return changed;
    }

    int rotatedDigits(int n) {
        int count = 0;

        for (int i = 1; i <= n; i++) {
            if (isGood(i)) count++;
        }

        return count;
    }
};