class Solution {
public:

    void updateFreq(int op, int val, vector<int>& freqBits) {
        int i = 0;
        while(val > 0) {
            if((val & 1)) {
                freqBits[i] += op; 
            }

            val /= 2;
            i++;
        }
    }

    int minimumDifference(vector<int>& nums, int k) {
        vector<int> freqBits(32, 0);

        int n = nums.size();

        int i = 0;
        int j = 0;
        int windowOr = nums[0];
        int result = INT_MAX;

        while(j < n) {
            windowOr = windowOr | nums[j];
            updateFreq(1, nums[j], freqBits);

            result = min(result, abs(k - windowOr));

            if(windowOr < k) {
                j++;
            } else if (windowOr == k) { 
                return 0;
            } else {
                while(i < j && windowOr > k) {
                    updateFreq(-1, nums[i], freqBits);
                    i++;
                    windowOr = 0;
                    for(int b = 0; b < 32; b++){
                        if( freqBits[b]>0) { 
                            windowOr = windowOr | (1<<b);
                        }
                    }
                    result = min(result, abs(k-windowOr));
                }
                j++;
            }
        }

        return result;
    }
};