class Solution {
public:
    void rotate(vector<int>& arr, int k) {
        int n=arr.size();
        k=k%n;
        if(k==0)
        return ;
        ::rotate(begin(arr),end(arr)-k,end(arr));//right rotate
    }
};