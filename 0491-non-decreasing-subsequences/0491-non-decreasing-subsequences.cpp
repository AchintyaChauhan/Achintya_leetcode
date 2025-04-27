class Solution {
public:
    int n;
    void solve(vector<int>& nums, vector<int>& curr, vector<vector<int>>& result, int i) {
        if (curr.size() >= 2) {
            result.push_back(curr);
        }
        unordered_set<int> st;

        for (int j = i; j < n; j++) {
            if ((curr.empty() || curr.back() <= nums[j]) && st.find(nums[j]) == st.end()) {
                curr.push_back(nums[j]); // pick
                solve(nums, curr, result, j + 1); // explore
                curr.pop_back(); // not pick

                st.insert(nums[j]);
            }
        }
    }    
    
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        n = nums.size();
        vector<int> curr;
        vector<vector<int>> result;
        solve(nums, curr, result, 0);
        return result;
    }
};
