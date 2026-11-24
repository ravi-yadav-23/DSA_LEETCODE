class Solution {
public:
    int change(int amount, vector<int>& coins) {
        vector<unsigned long long> dp(amount + 1, 0ULL);
        dp[0] = 1ULL;
        for (int c : coins) {
            for (int i = c; i <= amount; ++i) {
                dp[i] += dp[i - c];
            }
        }
        return static_cast<int>(dp[amount]);
    }
};