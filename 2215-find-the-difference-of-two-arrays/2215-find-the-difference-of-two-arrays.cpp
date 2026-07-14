class Solution
{
    public:
        vector<vector < int>> findDifference(vector<int> &num1, vector<int> &num2)
        {

            set<int> s1, s2, s3, s4;

            s1.insert(num1.begin(), num1.end());
            s2.insert(num2.begin(), num2.end());

            set_difference(s1.begin(), s1.end(),
                s2.begin(), s2.end(),
                inserter(s3, s3.begin()));

            set_difference(s2.begin(), s2.end(),
                s1.begin(), s1.end(),
                inserter(s4, s4.begin()));

            vector<int> v1(s3.begin(), s3.end());
            vector<int> v2(s4.begin(), s4.end());

            return {
                v1,
                v2
            };
        }
};