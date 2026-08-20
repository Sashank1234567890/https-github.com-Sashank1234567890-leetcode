class Solution {
public:
    vector<int> resultArray(vector<int>& nums) {
        int n=nums.size();

        if(n<=1)
            return nums;

        vector<int> result;
        vector<int> arr;

        result.push_back(nums[0]);
        arr.push_back(nums[1]);

        for(int i=2;i<n;i++){
            if(result.back()>arr.back())
                result.push_back(nums[i]);
            else
                arr.push_back(nums[i]);
        }

        result.insert(end(result),begin(arr),end(arr));

        return result;
    }
};