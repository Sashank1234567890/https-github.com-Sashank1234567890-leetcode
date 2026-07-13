class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {

        vector<long long> number;
        vector<long long> start;

        start.push_back(12);
        start.push_back(123);
        start.push_back(1234);
        start.push_back(12345);
        start.push_back(123456);
        start.push_back(1234567);
        start.push_back(12345678);
        start.push_back(123456789);

        number.push_back(12);

        long long add = 11;
        int idx = 1;

        while (number.back() <= min(1LL*high,123456789LL)) {

            if (number.back() % 10 == 9) {

                add = add * 10 + 1;

                if (idx < start.size())
                    number.push_back(start[idx++]);
                else
                    break;
            }
            else {
                number.push_back(number.back() + add);
            }
        }

        vector<int> ans;

        for (long long x : number) {
            if (x >= low && x <= high)
                ans.push_back(x);
        }

        return ans;
    }
};