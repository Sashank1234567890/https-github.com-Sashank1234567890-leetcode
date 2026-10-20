class Solution
{
    public:
        bool isRotation(vector<int> &vec1, vector<int> &vec2)
        {
            vector<int> temp = vec1;
            sort(temp.begin(), temp.end());
            if (temp != vec2)
            {
                return false;
            }
            int n = vec1.size();
            int count = 0;
            for (int i = 0; i < n; i++)
            {
                if (vec1[i] > vec1[(i + 1) % n])
                {
                    count++;
                }
            }
            return count <= 1;
        }
    int sortableIntegers(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> sorted = nums;
        sort(sorted.begin(), sorted.end());
        int result = 0;
        for (int k = 1; k <= n; k++)
        {
            if (n % k != 0) continue;
            bool valid = true;
            for (int start = 0; start < n; start += k)
            {
                vector<int> vec1(nums.begin() + start, nums.begin() + start + k);
                vector<int> vec2(sorted.begin() + start, sorted.begin() + start + k);
                if (!isRotation(vec1, vec2))
                {
                    valid = false;
                    break;
                }
            }
            if (valid)
            {
                result += k;
            }
        }
        return result;
    }
};