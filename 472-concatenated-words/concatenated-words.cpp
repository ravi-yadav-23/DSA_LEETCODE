class Solution {
public:
    bool canForm(const string& word, const unordered_set<string>& dict) {
        int n = word.size();
        if (n == 0) return false;
        vector<bool> dp(n + 1, false);
        dp[0] = true;
        for (int i = 1; i <= n; ++i) {
            for (int j = 0; j < i; ++j) {
                if (j == 0 && i == n) continue;
                if (dp[j] && dict.count(word.substr(j, i - j))) {
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[n];
    }

    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        unordered_set<string> dict(words.begin(), words.end());
        vector<string> ans;
        for (const string& w : words) {
            if (!w.empty() && canForm(w, dict)) {
                ans.push_back(w);
            }
        }
        return ans;
    }
};