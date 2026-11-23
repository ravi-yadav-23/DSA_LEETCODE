class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> ans;
        int n = s.size(), m = p.size();
        if (n < m) return ans;
        vector<int> cnt(26, 0);
        for (char c : p) cnt[c - 'a']++;
        int rem = m;
        for (int i = 0; i < n; ++i) {
            if (--cnt[s[i] - 'a'] >= 0) rem--;
            if (i >= m) {
                if (++cnt[s[i - m] - 'a'] > 0) rem++;
            }
            if (rem == 0) ans.push_back(i - m + 1);
        }
        return ans;
    }
};