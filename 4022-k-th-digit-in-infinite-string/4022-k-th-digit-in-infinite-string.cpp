class Solution {
public:
    int kthDigit(long long k) {
        if(k<=9)
            return k;

        k-=9;

        long long b=1;
        long long cnt=9;

  
        while(true){
            long long digit=to_string(10*b).size();
            long long total=cnt*10*digit;

            if(k<=total)
                break;

            k-=total;
            b*=10;
            cnt*=10;
        }

     
        long long digit=to_string(10*b).size();
        long long block=(k-1)/(10*digit);
        long long pos=(k-1)%(10*digit);

        b+=block;

        long long f=10*b;
        long long a=pos/digit;
        long long p=pos%digit;

        long long num;

        if(b%2)
            num=f+9-a;
        else
            num=f+a;

        string s=to_string(num);

        return s[p]-'0';
    }
};