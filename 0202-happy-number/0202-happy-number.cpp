class Solution {
public:
    int nextNum(int n) {
        int sum = 0;

        while (n) {
            int d = n % 10;
            sum += d * d;
            n /= 10;
        }

        return sum;
    }

    bool isHappy(int n) {

        int slow = n;
        int fast = n;

        while (true) {
            slow = nextNum(slow);
            fast = nextNum(nextNum(fast));

            if (slow == fast)
                break;
        }

        return slow == 1;
    }
};