class Solution {
public:
    // int fibbo(int n){
    //     if(n==0) return 0;
    //     if(n==1) return 1;
    //     return fibbo(n-1)+fibbo(n-2);
    // }
    int fib(int n) {
        if(n==0) return 0;
        if(n==1) return 1;
        return fib(n-1)+fib(n-2);
    }
};