class Solution {
public:
    vector<int> freq(long long n) {
        vector<int> f(10, 0);

        while(n > 0) {
            f[n % 10]++;
            n /= 10;
        }

        return f;
    }

    bool reorderedPowerOf2(int n) {
        vector<int> f = freq(n);

        for(int i = 0; i <= 30; i++) {
            long long x = 1LL << i;

            if(freq(x) == f) return true;
        }

        return false;
    }
};