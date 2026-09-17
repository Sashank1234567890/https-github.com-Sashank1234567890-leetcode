class Solution {
public:
    string frequencySort(string s) {
        vector<int>freq(256,0);
        for(char &x:s){
            freq[x]++;
        }
        auto lambda=[&](char a,char b){
            if(freq[a]==freq[b]){
                return a<b;
            }
            return freq[a]>freq[b];//use strict ordering >
        };
        ranges::sort(s,lambda);
        return s;
    }
};