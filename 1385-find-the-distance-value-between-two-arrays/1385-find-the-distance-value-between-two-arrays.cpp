class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        int n=arr1.size();
        int m=arr2.size();
        sort(begin(arr2),end(arr2));
        int cnt=0;
        for(int i=0;i<n;i++){
            int idx=upper_bound(begin(arr2),end(arr2),arr1[i])-begin(arr2);
            if(idx>0){
                if(abs(arr2[idx-1]-arr1[i])<=d)
                continue;
            }
            if(idx>1){
                 if(abs(arr2[idx-2]-arr1[i])<=d)
                continue;
            }

            if(idx!=m){
                  if(abs(arr2[idx]-arr1[i])<=d)
                continue;
            }
            cnt++;
        }
    return cnt;}
};