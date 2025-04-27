class Solution {
public:
    int ans = INT_MIN;
    int m;

    void solve(int i, int count, int n, vector<int>& result, vector<vector<int>>& requests) {
        if (i >= m) {
            bool found = true;
            for (auto it : result) {
                if (it != 0) {
                    found = false;
                    break;
                }
            }
            if (found) {
                ans = max(ans, count);
            }
            return;
        }

        int from = requests[i][0];
        int to = requests[i][1];

        // Take this request
        result[from]--;
        result[to]++;
        solve(i + 1, count + 1, n, result, requests);

        // Not take this request (undo the move)
        result[from]++;
        result[to]--;
        solve(i + 1, count, n, result, requests);
    }

    int maximumRequests(int n, vector<vector<int>>& requests) {
        m = requests.size();
        vector<int> result(n, 0);
        solve(0, 0, n, result, requests);
        return ans;
    }
};
