class Solution {
public:
    int maxDiff(int num) {
        string s = to_string(num);

        string mx = s;
        for (char c : mx) {
            if (c != '9') {
                char x = c;
                for (char &d : mx) {
                    if (d == x)
                        d = '9';
                }
                break;
            }
        }

        string mn = s;

        if (mn[0] != '1') {
            char x = mn[0];
            for (char &d : mn) {
                if (d == x)
                    d = '1';
            }
        } else {
            for (int i = 1; i < mn.size(); i++) {
                if (mn[i] != '0' && mn[i] != '1') {
                    char x = mn[i];
                    for (char &d : mn) {
                        if (d == x)
                            d = '0';
                    }
                    break;
                }
            }
        }

        return stoi(mx) - stoi(mn);
    }
};