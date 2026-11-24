class Solution {
public:
    long long cross(const vector<int>& o, const vector<int>& a, const vector<int>& b) {
        return 1LL * (a[0] - o[0]) * (b[1] - o[1]) - 1LL * (a[1] - o[1]) * (b[0] - o[0]);
    }

    vector<vector<int>> outerTrees(vector<vector<int>>& trees) {
        int n = trees.size();
        if (n <= 3) return trees;
        sort(trees.begin(), trees.end(), [](const vector<int>& a, const vector<int>& b) {
            if (a[0] != b[0]) return a[0] < b[0];
            return a[1] < b[1];
        });
        vector<vector<int>> hull;
        for (int i = 0; i < n; ++i) {
            while (hull.size() >= 2 && cross(hull[hull.size() - 2], hull.back(), trees[i]) < 0) {
                hull.pop_back();
            }
            hull.push_back(trees[i]);
        }
        int lowerSize = hull.size();
        for (int i = n - 2; i >= 0; --i) {
            while (hull.size() > lowerSize && cross(hull[hull.size() - 2], hull.back(), trees[i]) < 0) {
                hull.pop_back();
            }
            hull.push_back(trees[i]);
        }
        sort(hull.begin(), hull.end());
        hull.erase(unique(hull.begin(), hull.end()), hull.end());
        return hull;
    }
};