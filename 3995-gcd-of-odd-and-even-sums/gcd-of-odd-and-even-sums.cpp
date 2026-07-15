class Solution {
public:
    int gcd(int a,int b){
        if(a==0)
            return b;
        if(b==0)
            return a;
        if(a==b)
            return a;
        if(a>b)
            return gcd(a-b,b);

        return gcd(a,b-a);
    }
    int gcdOfOddEvenSums(int n){
        if(n==0) return 0;
        int sumOdd=0,sumEven=0;
        sumEven=(n*(2+2*n))/2;
        sumOdd=n*n;
        int gc=gcd(sumOdd,sumEven);
        return gc;
    }
};