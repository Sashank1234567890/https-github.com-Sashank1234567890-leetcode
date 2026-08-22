class segTree{
public:

    struct Node{
        bool valid;
        bool first;
        bool last;
    };

    vector<Node> seg;

    segTree(int n){
        seg.assign(4*n,{0,0,0});
    }

    Node build(vector<int>&arr,int i,int l,int r){
        if(l==r){
            seg[i]={1,(arr[l]%2==1),(arr[l]%2==1)};
            return seg[i];
        }

        int mid=l+(r-l)/2;

        auto left=build(arr,2*i+1,l,mid);
        auto right=build(arr,2*i+2,mid+1,r);

        if(!left.valid||!right.valid){
            return seg[i]={0,left.first,right.last};
        }

        if(left.last==right.first){
            return seg[i]={0,left.first,right.last};
        }

        return seg[i]={1,left.first,right.last};
    }

    Node query(int start,int end,int i,int l,int r){

        if(l>end||r<start){
            return {0,0,0};
        }

        if(start<=l&&r<=end){
            return seg[i];
        }

        int mid=l+(r-l)/2;

        if(end<=mid){
            return query(start,end,2*i+1,l,mid);
        }

        if(start>mid){
            return query(start,end,2*i+2,mid+1,r);
        }

        auto left=query(start,end,2*i+1,l,mid);
        auto right=query(start,end,2*i+2,mid+1,r);

        if(!left.valid||!right.valid){
            return {0,left.first,right.last};
        }

        if(left.last==right.first){
            return {0,left.first,right.last};
        }

        return {1,left.first,right.last};
    }
};

class Solution {
public:
    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {

        int n=nums.size();

        segTree st(n);

        st.build(nums,0,0,n-1);

        vector<bool> ans;

        for(auto q:queries){

            int l=q[0];
            int r=q[1];

            auto x=st.query(l,r,0,0,n-1);

            ans.push_back(x.valid);
        }

        return ans;
    }
};