class Solution
{
    public:
        vector<vector < int>> findDifference(vector<int> &num1, vector<int> &num2)
        {

            set<int> s1, s2, s3, s4;

            s1.insert(num1.begin(), num1.end());
            s2.insert(num2.begin(), num2.end());

            vector<int> v1, v2;

            set_difference(s1.begin(), s1.end(),
                s2.begin(), s2.end(),
                back_inserter(v1));

            set_difference(s2.begin(), s2.end(),
                s1.begin(), s1.end(),
                back_inserter(v2));

            return {
                v1,
                v2
            };

            return {
                v1,
                v2
            };
        }
};