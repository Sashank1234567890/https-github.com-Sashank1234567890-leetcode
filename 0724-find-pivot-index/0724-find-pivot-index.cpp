class Solution{
public:

    int pivotIndex(vector<int>& a) {

        int n = a.size();

        if(n == 1)
            return 0;

        long long left_sum = 0;
        long long totalSum = 0;

        for(int &x : a)
            totalSum += x;

        for(int i = 0; i < n; i++) {

            long long right_sum = totalSum - left_sum - a[i];

            if(left_sum == right_sum)
                return i;

            left_sum += a[i];
        }

        return -1;
    }
};