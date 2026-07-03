class Solution {
public:

    int kth(vector<int>& a, int i,
            vector<int>& b, int j,
            int k) {

        // One array finished
        if(i >= a.size())
            return b[j + k - 1];

        if(j >= b.size())
            return a[i + k - 1];

        // Smallest element
        if(k == 1)
            return min(a[i], b[j]);

        int half = k / 2;

        int mid1 = INT_MAX;
        int mid2 = INT_MAX;

        if(i + half - 1 < a.size())
            mid1 = a[i + half - 1];

        if(j + half - 1 < b.size())
            mid2 = b[j + half - 1];

        if(mid1 < mid2)
            return kth(a, i + half, b, j, k - half);

        return kth(a, i, b, j + half, k - half);
    }

    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {

        int total = nums1.size() + nums2.size();

        if(total % 2)
            return kth(nums1, 0, nums2, 0, total / 2 + 1);

        int left = kth(nums1, 0, nums2, 0, total / 2);

        int right = kth(nums1, 0, nums2, 0, total / 2 + 1);

        return (left + right) / 2.0;
    }
};