class Solution {
public:
    int numberOfArrays(vector<int>& nums, int lower, int upper) {
        long long mini = 0, maxi = 0, curr = 0;
        for (int it : nums) {
            curr += it;
            mini = min(mini, curr);
            maxi = max(maxi, curr);
        }

        long long minStart = (long long)lower - mini;
        long long maxStart = (long long)upper - maxi;
        long long ans = maxStart - minStart + 1;

        return max(0LL, ans);
    }
};
