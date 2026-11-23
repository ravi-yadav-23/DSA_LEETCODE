class Solution {
public:
    string minWindow(string s, string t) {
        if (s.empty() || t.empty() || s.size() < t.size()) return "";
        vector<int> need(128, 0);
        for (char c : t) need[c]++;
        int required = t.size();
        int left = 0, right = 0;
        int minLen = INT_MAX, startIdx = 0;
        while (right < (int)s.size()) {
            if (need[s[right]] > 0) required--;
            need[s[right]]--;
            right++;
            while (required == 0) {
                if (right - left < minLen) {
                    minLen = right - left;
                    startIdx = left;
                }
                need[s[left]]++;
                if (need[s[left]] > 0) required++;
                left++;
            }
        }
        return minLen == INT_MAX ? "" : s.substr(startIdx, minLen);
    }
};