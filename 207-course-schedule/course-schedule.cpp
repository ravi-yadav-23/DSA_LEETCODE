class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        vector<int> indegree(numCourses,0);

        for (const auto& pre:prerequisites) {
            int course = pre[0];
            int prereq = pre[1];

            adj[prereq].push_back(course);
            indegree[course]++;

        }

        queue<int> q;
        for (int i=0; i<numCourses;++i) {
            if (indegree[i]==0) {
                q.push(i);
            }
        }



        int coursesTaken=0;

        while (!q.empty()) {
            int current = q.front();
            q.pop();
            coursesTaken++;
            
            for (int neighbor : adj[current]) {
                indegree[neighbor]--;
        if (indegree[neighbor] == 0) {
                    q.push(neighbor);
                }
            }
        }

    return coursesTaken == numCourses;
    }
};