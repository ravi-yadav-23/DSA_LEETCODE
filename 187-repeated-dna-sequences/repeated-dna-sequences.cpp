class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        int n = s.size();
        if (n < 10) return {};
        unordered_map<int, int> code = {{'A', 0}, {'C', 1}, {'G', 2}, {'T', 3}};
        unordered_map<int, int> seen;
        vector<string> res;
        int mask = (1 << 20) - 1;
        int hash = 0;
        for (int i = 0; i < n; ++i) {
            hash = ((hash << 2) & mask) | code[s[i]];
            if (i >= 9) {
                if (++seen[hash] == 2) {
                    res.push_back(s.substr(i - 9, 10));
                }
            }
        }
        return res;
    }
};