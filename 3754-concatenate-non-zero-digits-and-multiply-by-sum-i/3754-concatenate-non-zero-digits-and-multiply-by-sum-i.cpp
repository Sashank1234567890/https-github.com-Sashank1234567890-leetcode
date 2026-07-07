class Solution {
public:
    long long sumAndMultiply(int n) {
        long long sum=0;
        long long int num=0;
        long long f=1;
        while(n){
            int r=n%10;
            n=n/10;
            if(r){
                num=num+r*f;
                f*=10;
                sum+=r;
            }
            
        }
    return sum*num;}
};