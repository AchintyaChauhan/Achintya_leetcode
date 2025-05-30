class Solution {
public:
    void bfs(int start, vector<int>& dist, vector<vector<int>>& adj) {
        int n = adj.size();
        vector<bool> visited(n, false);
        queue<pair<int, int>> q;
        q.push({0, start});
        visited[start] = true;
        dist[start] = 0;

        while (!q.empty()) {
            auto [d, node] = q.front();
            q.pop();

            for (int neighbor : adj[node]) {
                if (!visited[neighbor]) {
                    visited[neighbor] = true;
                    dist[neighbor] = d + 1;
                    q.push({d + 1, neighbor});
                }
            }
        }
    }

    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        int n = edges.size();
        vector<vector<int>> adj(n);
        for (int i = 0; i < n; ++i) {
            if (edges[i] != -1)
                adj[i].push_back(edges[i]);
        }

        vector<int> dist1(n, 1e9), dist2(n, 1e9);
        bfs(node1, dist1, adj);
        bfs(node2, dist2, adj);

        int minDist = 1e9, ans = -1;
        for (int i = 0; i < n; ++i) {
            if (dist1[i] != 1e9 && dist2[i] != 1e9) {
                int maxDist = max(dist1[i], dist2[i]);
                if (maxDist < minDist) {
                    minDist = maxDist;
                    ans = i;
                }
            }
        }
        return ans;
    }
};
