class Solution {
public:
    double power(double x, long long n){
        if(x==1.0 || n==0) return 1;
        if(x==0) return 0;
        if(n==1) return x;
        if(n&1)//odd
            return x*power(x,n-1);
        else
            return power(x*x,n/2);
    }
    double myPow(double x, int n) {
        if (n < 0)
            return (1.0 / power(x, -1.0 * n));
        return power(x, n);
    }
};