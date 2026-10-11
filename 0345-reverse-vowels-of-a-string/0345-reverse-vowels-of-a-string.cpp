class Solution {
public:
    string reverseVowels(string s) {
        int i=0,j=s.size()-1;
        auto isVowel=[&](char ch){
                  return ch=='a'||ch=='i'||ch=='e'||ch=='o'||ch=='u';
        };
        while(i<j){
            while(i<j&& !isVowel(tolower(s[i]))){
                i++;
            }
            while(j>i&& !isVowel(tolower(s[j]))){
                j--;
            }
            if(i==j){
                return s;
            }
            swap(s[i++],s[j--]);
        }
    return s;}
};