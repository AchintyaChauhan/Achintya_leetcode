class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        if (grid[0][0] == 1 || grid[n-1][m-1] == 1)
            return -1;

        if (n == 1 && m == 1 && grid[0][0] == 0)
            return 1;

        vector<vector<int>> dis(n, vector<int>(m, 1e9));
        queue<pair<int, pair<int, int>>> q;
        vector<pair<int, int>> dir = {
            {0, 1}, {0, -1}, {1, 0}, {-1, 0},
            {1, 1}, {1, -1}, {-1, 1}, {-1, -1}
        };

        dis[0][0] = 1;  
        q.push({1, {0, 0}});

        while (!q.empty()) {
            int d = q.front().first;
            int i = q.front().second.first;
            int j = q.front().second.second;
            q.pop();

            for (auto it : dir) {
                int x = i + it.first;
                int y = j + it.second;

            if (x >= 0 && x < n && y >= 0 && y < m && grid[x][y] == 0 && dis[x][y] > d + 1) {
                    dis[x][y] = d + 1;
                    q.push({d + 1, {x, y}});
                }
            }
        }

        return (dis[n-1][m-1] == 1e9) ? -1 : dis[n-1][m-1];
    }
};
