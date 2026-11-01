class Solution {
public:
    long long minimumMaxValue(int n, int index, int value) {
        if(value==1)
            return -1;

        int lpf=value;

        // lpf is the smallest prime factor of value.
        // Any smaller number having GCD > 1 with value
        // must be a multiple of one of its prime factors.
        // Hence, the closest possible smaller number is value-lpf.
        for(int i=2;i*i<=value;i++){
            if(value%i==0){
                lpf=i;
                break;
            }
        }


        // value-lpf is always even:
        // - Even value: lpf = 2.
        // - Odd composite value: both value and lpf are odd.
        // After reaching an even number, we can keep subtracting 2
        // because GCD of two consecutive even numbers is at least 2.
        long long left=(value-lpf)/2;

        if(index>left)
            return -1;

        int right=n-index-1;
        long long ans=value;

        // The closest greater number sharing a factor with value is
        // value+lpf. This is always even, so subsequent elements
        // can increase by 2 while maintaining GCD >= 2.
        if(right>0){
            ans=1LL*value+lpf+2LL*(right-1);
        }

        return ans;
    }
};