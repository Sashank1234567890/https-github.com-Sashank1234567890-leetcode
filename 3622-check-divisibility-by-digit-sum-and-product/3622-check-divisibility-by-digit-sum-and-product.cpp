class Solution {
public:
    bool checkDivisibility(int n) {
        long long sum=0;
        long long ds=0;
        long long p=1;
        int a=n;
        while(a){
           int ld=a%10;
           a=a/10;
           p*=ld;
           ds+=ld;
        }
        return (n%(ds+p))==0;
    }
};