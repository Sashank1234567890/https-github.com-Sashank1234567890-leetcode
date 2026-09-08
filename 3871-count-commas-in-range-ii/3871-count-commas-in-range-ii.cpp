class Solution {
public:
    long long power(long long n, long long k) {
        if(k == 0)
            return 1;

        long long x = power(n, k / 2);

        long long ans = x * x;

        if(k & 1)
            ans *= n;

        return ans;
    }

    long long countCommas(long long n) {
        if(n <= 999)
            return 0;

        long long k = 0;
        long long d = n;

        while(d > 999) {
            k++;
            d /= 1000;
        }

        long long ans = 0;

        while(k > 0) {
            long long limit = power(1000, k);

            ans += n - limit + 1;

            k--;
        }

        return ans;
    }
};