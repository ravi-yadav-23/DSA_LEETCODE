class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int> st;
        st.reserve(n);
        long long maxArea = 0;

        for (int i = 0; i <= n; ++i) {
            int currH = (i == n) ? 0 : heights[i];
            while (!st.empty() && currH < heights[st.back()]) {
                int h = heights[st.back()];
                st.pop_back();
                int leftIdx = st.empty() ? -1 : st.back();
                long long width = i - leftIdx - 1;
                maxArea = max(maxArea, 1LL * h * width);
            }
            st.push_back(i);
        }

        return static_cast<int>(maxArea);
    }
};