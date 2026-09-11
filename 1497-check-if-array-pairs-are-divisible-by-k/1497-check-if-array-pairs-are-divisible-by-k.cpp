class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        int cnt=arr.size();
        unordered_map<int,int>mp;
        for(int&x : arr){
            int ele=(x%k+k)%k;
            // cout<<ele<<endl;
            int rem=(k-x%k)%k;
            //  cout<<rem<<endl;
            if(mp[rem]){
                mp[rem]--;
                cnt-=2;
            }else{
                mp[ele]++;
            }
        }
    return cnt==0;}
};