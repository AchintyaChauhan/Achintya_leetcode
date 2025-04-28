class Solution {
public:
    int n;
    int ans;

    void solve(int i, unordered_map<int, int> &mpp, vector<int> &nums, int k) {
        if (i >= n) {
                ans++;
            return;
        }
        // not take 
        solve(i + 1, mpp, nums, k);

        // take
        if (mpp[nums[i] - k] == 0 && mpp[nums[i] + k] == 0) {
            mpp[nums[i]]++;
            solve(i + 1, mpp, nums, k);
            mpp[nums[i]]--;
        }
    }

    int beautifulSubsets(vector<int> &nums, int k) {
        n = nums.size();
        ans = 0;
        unordered_map<int, int> mpp;

        solve(0, mpp, nums, k);

        return ans-1;
        // remove empty subset , given in ques
    }
};
