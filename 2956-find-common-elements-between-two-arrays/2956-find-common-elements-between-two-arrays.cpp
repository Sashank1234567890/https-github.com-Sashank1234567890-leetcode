class Solution {
public:
    vector<int> findIntersectionValues(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());

        int i = 0, j = 0;
        int answer1 = 0, answer2 = 0;

        while (i < nums1.size() && j < nums2.size()) {
            if (nums1[i] == nums2[j]) {
                int x = nums1[i];

                int c1 = 0, c2 = 0;

                while (i < nums1.size() && nums1[i] == x) {
                    c1++;
                    i++;
                }

                while (j < nums2.size() && nums2[j] == x) {
                    c2++;
                    j++;
                }

                answer1 += c1;
                answer2 += c2;
            }
            else if (nums1[i] < nums2[j]) {
                i++;
            }
            else {
                j++;
            }
        }

        return {answer1, answer2};
    }
};