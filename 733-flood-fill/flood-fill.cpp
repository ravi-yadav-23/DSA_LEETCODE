class Solution {
public:
    void dfs(vector<vector<int>>& image, int r, int c, int origColor, int newColor) {
        int m = image.size();
        int n = image[0].size();
        if (r < 0 || r >= m || c < 0 || c >= n || image[r][c] != origColor) {
            return;
        }
        image[r][c] = newColor;
        dfs(image, r + 1, c, origColor, newColor);
        dfs(image, r - 1, c, origColor, newColor);
        dfs(image, r, c + 1, origColor, newColor);
        dfs(image, r, c - 1, origColor, newColor);
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int origColor = image[sr][sc];
        if (origColor == color) {
            return image;
        }
        dfs(image, sr, sc, origColor, color);
        return image;
    }
};