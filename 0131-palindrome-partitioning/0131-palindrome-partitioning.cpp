class Solution {
public:
    bool ispalindrome(string s) {
        int i = 0, j = s.size() - 1;
        while (i < j) {
            if (s[i++] != s[j--]) return false;
        }
        return true;
    }

    void solve(int i, string &s, vector<string>& curr, vector<vector<string>>& result) {
        if (i == s.size()) {
            result.push_back(curr);
            return;
        }

        for (int j = i; j < s.size(); j++) {
            string temp = s.substr(i, j - i + 1);
            if (ispalindrome(temp)) {
                curr.push_back(temp);
                solve(j + 1, s, curr, result);
                curr.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) {
        vector<vector<string>> result;
        vector<string> curr;
        solve(0, s, curr, result);
        return result;
    }
};
