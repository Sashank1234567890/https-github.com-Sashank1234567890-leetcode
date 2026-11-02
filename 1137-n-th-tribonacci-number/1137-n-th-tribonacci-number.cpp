class Solution {
public:
    int tribonacci(int n) {
        int f=1,s=1,t=0;
        if(n==0)
        return 0;
        if(n<=2)
        return 1;
        for(int i=3;i<=n;i++){
            int curr=f+s+t;
            t=s;
            s=f;
            f=curr;
        }
        return f;
    }
};