class Solution {
public:
    vector<int>temp;
    int dac(vector<int>& nums,int l,int r){
        if(l>=r)
        return 0;
        int mid=l+(r-l)/2;
        int left=dac(nums,l,mid);
        int right=dac(nums,mid+1,r);
        
        int i=l,j=mid+1,k=l;
        int cnt=0;
        while(i<=mid&&j<=r){
            // for(int &x:temp){
            //     cout<<x<<" ";
            // }
            // cout<<endl;
            if(1LL*nums[i]>2LL*nums[j]){
                // cout<<mid-i+1<<endl;
                  cnt+=mid-i+1;
                    temp[k++]=nums[j++];
              
            }else{
                    temp[k++]=nums[i++];
            }
        }
        i=l,j=mid+1,k=l;
         while(i<=mid&&j<=r){
            // for(int &x:temp){
            //     cout<<x<<" ";
            // }
            // cout<<endl;
            if(nums[i]>nums[j]){
                // cout<<mid-i+1<<endl;
                //   cnt+=mid-i+1;
                    temp[k++]=nums[j++];
              
            }else{
                    temp[k++]=nums[i++];
            }
        }
        while(i<=mid){
             temp[k++]=nums[i++];
        }
        while(j<=r){
              temp[k++]=nums[j++];
        }
        
        for(int p=l;p<=r;p++){
            nums[p]=temp[p];
        }

        return left+right+cnt;

    }
    int reversePairs(vector<int>& nums) {
        int n=nums.size();
        temp=nums;
        return dac(nums,0,n-1);
    }
};