class Solution {
public:
int reverse(int n){
    int num=0;
    while(n>0){
        int digit=n%10;
         num=10*num+digit;
        n/=10;
    }
    return num;
}

    int mirrorDistance(int n) {
        int val=reverse(n);
        return abs(n-val);
        
    }
};