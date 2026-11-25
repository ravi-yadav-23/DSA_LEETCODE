class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        if (source == destination) return true;
        vector<vector<int>> adj(n);
        for (const auto& e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        vector<bool> visited(n, false);
        queue<int> q;
        visited[source] = true;
        q.push(source);
        while (!q.empty()) {
            int curr = q.front();
            q.pop();
            if (curr == destination) return true;
            for (int nxt : adj[curr]) {
                if (!visited[nxt]) {
                    visited[nxt] = true;
                    q.push(nxt);
                }
            }
        }
        return false;
    }
};