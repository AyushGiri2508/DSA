// class Solution {
// public:
//     int minMoves(int target, int maxDoubles) {
//         int cnt=0;
//         if(maxDoubles==0){
//             return target-1;
//         }
//         while(target>0){
//         if(target%2!=0){
//             cnt++;
//              target-=1;
//         }
//         else if(target%2==0&&maxDoubles>0){
//             target/=2;
//             maxDoubles--;
//             cnt++;
//         }
//         else{
//             cnt++;
//             target-=1;
//         }
//         }
//         return cnt-1;
//     }
// };
class Solution {
public:
    int minMoves(int target, int maxDoubles) {
        int moves = 0;

        while (target > 1 && maxDoubles > 0) {
            if (target % 2 == 0) {
                target /= 2;
                maxDoubles--;
            } else {
                target--;
            }
            moves++;
        }

        // If no doubles remain, only decrement operations are possible
        moves += (target - 1);

        return moves;
    }
};