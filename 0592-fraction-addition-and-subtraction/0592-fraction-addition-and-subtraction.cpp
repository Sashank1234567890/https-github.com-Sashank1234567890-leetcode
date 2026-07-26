class Solution {
public:
    string fractionAddition(string expression) {

        stringstream ss(expression);

        long long num = 0, den = 1;
        long long a, b;
        char slash;

        while (ss >> a >> slash >> b) {

            num = num * b + a * den;
            den = den * b;

            long long g = gcd(abs(num), den);

            num /= g;
            den /= g;
        }

        return to_string(num) + "/" + to_string(den);
    }
};