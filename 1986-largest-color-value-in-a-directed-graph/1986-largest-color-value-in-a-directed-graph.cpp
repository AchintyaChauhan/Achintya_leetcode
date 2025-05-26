class Solution {
public:
    int largestPathValue(string colors, vector<vector<int>>& edges) {
        int n = colors.size();
        vector<vector<int>> adj(n);
        vector<int> indegree(n, 0);
        vector<vector<int>> t(n, vector<int>(26, 0));
        queue<int> q;

        for (auto& it : edges) {
            int u = it[0], v = it[1];
            adj[u].push_back(v);
            indegree[v]++;
        }

        for (int i = 0; i < n; ++i) {
            if (indegree[i] == 0) {
                q.push(i);
                t[i][colors[i] - 'a'] = 1;
            }
        }

        int count = 0;
        int ans = 0;

        while (!q.empty()) {
            int node = q.front();
            q.pop();
            count++;

            for (int v : adj[node]) {
                for (int i = 0; i < 26; ++i) {
                    int extra = (colors[v] - 'a' == i) ? 1 : 0;
                    t[v][i] = max(t[v][i], t[node][i] + extra);
                }

                indegree[v]--;
                if (indegree[v] == 0) {
                    q.push(v);
                }
            }

            ans = max(ans, t[node][colors[node] - 'a']);
        }
        if(count<n){
            return -1;
        }

        return ans;
    }
};
