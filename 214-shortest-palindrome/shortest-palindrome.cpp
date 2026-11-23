class Solution {
public:
    string shortestPalindrome(string s) {
        int n = s.size();
        if (n <= 1) return s;
        string rev = s;
        reverse(rev.begin(), rev.end());
        string comb = s + "#" + rev;
        int m = comb.size();
        vector<int> lps(m, 0);
        for (int i = 1; i < m; ++i) {
            int len = lps[i - 1];
            while (len > 0 && comb[i] != comb[len]) {
                len = lps[len - 1];
            }
            if (comb[i] == comb[len]) {
                len++;
            }
            lps[i] = len;
        }
        int palLen = lps[m - 1];
        string prefix = rev.substr(0, n - palLen);
        return prefix + s;
    }
};