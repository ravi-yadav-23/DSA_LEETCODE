class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        long long totalSum = 0;
        for (int x : nums) {
            totalSum += x;
        }
        if (abs((long long)target) > totalSum || (totalSum + target) % 2 != 0) {
            return 0;
        }
        int subsetSum = (totalSum + target) / 2;
        vector<long long> dp(subsetSum + 1, 0);
        dp[0] = 1;
        for (int x : nums) {
            for (int s = subsetSum; s >= x; --s) {
                dp[s] += dp[s - x];
            }
        }
        return static_cast<int>(dp[subsetSum]);
    }
};