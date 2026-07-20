class Solution {
public:
    void rotate(vector<int>& arr, int k) {
        int n=arr.size();
        reverse(begin(arr),end(arr));
        reverse(begin(arr),begin(arr)+(k%n));
        reverse(begin(arr)+k%n,end(arr));
    }
};