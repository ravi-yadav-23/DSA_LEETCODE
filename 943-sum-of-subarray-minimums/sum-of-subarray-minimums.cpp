class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        const long long MOD = 1000000007LL;
        int n = arr.size();
        vector<int> st;
        st.reserve(n);
        long long ans = 0;

        for (int i = 0; i <= n; ++i) {
            int curr = (i == n) ? 0 : arr[i];
            while (!st.empty() && arr[st.back()] >= curr) {
                int mid = st.back();
                st.pop_back();
                int left = st.empty() ? -1 : st.back();
                long long leftCount = mid - left;
                long long rightCount = i - mid;
                long long contrib = ((leftCount * rightCount) % MOD) * (arr[mid] % MOD) % MOD;
                ans = (ans + contrib) % MOD;
            }
            st.push_back(i);
        }

        return static_cast<int>(ans);
    }
};
