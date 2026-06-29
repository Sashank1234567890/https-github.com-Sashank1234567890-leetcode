class Solution {
public:

    vector<int> parent, rank;

    int find(int x){

        if(parent[x]==x)
            return x;

        return parent[x]=find(parent[x]);
    }

    void Union(int x,int y){

        int px=find(x);
        int py=find(y);

        if(px==py)
            return;

        if(rank[px]>rank[py]){
            parent[py]=px;
        }
        else if(rank[px]<rank[py]){
            parent[px]=py;
        }
        else{
            parent[py]=px;
            rank[px]++;
        }
    }

    bool isSimilar(string &a,string &b){

        int diff=0;

        for(int i=0;i<a.size();i++){

            if(a[i]!=b[i])
                diff++;

            if(diff>2)
                return false;
        }

        return diff==0 || diff==2;
    }

    int numSimilarGroups(vector<string>& strs) {

        int n=strs.size();

        parent.resize(n);
        rank.assign(n,0);

        for(int i=0;i<n;i++)
            parent[i]=i;

        int groups=n;

        for(int i=0;i<n;i++){

            for(int j=i+1;j<n;j++){

                if(isSimilar(strs[i],strs[j])){

                    int pi=find(i);
                    int pj=find(j);

                    if(pi!=pj){
                        Union(pi,pj);
                        groups--;
                    }
                }
            }
        }

        return groups;
    }
};