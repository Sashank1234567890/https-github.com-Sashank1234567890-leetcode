class Solution
{
    public:
        int triangularSum(vector<int> &arr)
        {
            int sz = arr.size();
            while (sz > 1)
            {
                for (int i = 1; i < sz; i++)
                {
                    arr[i-1] = (arr[i-1] + arr[i])%10;
                }
                arr.resize(--sz);
            }   
        
        return arr[0];
        }
};