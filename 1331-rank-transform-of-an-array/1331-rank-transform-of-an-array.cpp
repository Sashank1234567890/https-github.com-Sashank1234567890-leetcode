class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        vector<int>sorted=arr;
        sort(begin(sorted),end(sorted));
        unordered_map<int,int>mp;
        int n =arr.size();
        int j=1;
        for(int i=0;i<n;i++){
            if(mp.contains(sorted[i]))
              continue;
            mp[sorted[i]]=j++;  
        }
        vector<int>ans(n,0);
        for(int i=0;i<n;i++){
         ans[i]=mp[arr[i]];
        }
    return ans;}
};