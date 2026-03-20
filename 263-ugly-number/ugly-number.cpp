class Solution {
public:
    bool isUgly(int n) {
    //     if(n<4){
    //         return true;
    //     }
    //     if((n%2==0&&n%3==0)||(n%6==0)||n%5==0){
    //         return true;
    //     }
        
    //   return false;  
     if(n <= 0) return false;

        while(n % 2 == 0) n /= 2;
        while(n % 3 == 0) n /= 3;
        while(n % 5 == 0) n /= 5;

        return n == 1;
    }
};