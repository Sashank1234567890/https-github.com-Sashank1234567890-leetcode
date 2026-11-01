class Solution
{
    public:
        int minMoves(vector<int> &nums)
        {
            int n = nums.size();//[1,2,3] =>[1,1,1] as n-1 krne  the so reverse krdo 1 element reduce 
            //1-1+2-1+3-1=3

            int sum = accumulate(begin(nums), end(nums), 0);
            int min_el = *min_element(begin(nums), end(nums));

            return sum - n * min_el;
        }
};