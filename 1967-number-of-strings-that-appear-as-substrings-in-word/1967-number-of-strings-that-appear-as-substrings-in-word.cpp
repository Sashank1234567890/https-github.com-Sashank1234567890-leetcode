class Solution {
public:

    vector<int> buildLPS(string &pat){

        int m = pat.size();

        vector<int> lps(m,0);

        int len = 0;
        int i = 1;

        while(i < m){

            if(pat[i] == pat[len]){
                len++;
                lps[i] = len;
                i++;
            }
            else{

                if(len != 0)
                    len = lps[len-1];
                else{
                    lps[i] = 0;
                    i++;
                }
            }
        }

        return lps;
    }

    bool KMP(string &text, string &pat){

        vector<int> lps = buildLPS(pat);

        int i = 0;
        int j = 0;

        while(i < text.size()){

            if(text[i] == pat[j]){
                i++;
                j++;
            }

            if(j == pat.size())
                return true;

            else if(i < text.size() && text[i] != pat[j]){

                if(j != 0)
                    j = lps[j-1];
                else
                    i++;
            }
        }

        return false;
    }

    int numOfStrings(vector<string>& patterns, string word) {

        int ans = 0;

        for(string &pat : patterns){

            if(KMP(word, pat))
                ans++;
        }

        return ans;
    }
};