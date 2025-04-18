class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n = nums.size();
        int mini = INT_MAX, maxi = INT_MIN;
        int minIndex = -1, maxIndex = -1;

        for (int i = 0; i < n; i++) {
            if (nums[i] > maxi) {
                maxi = nums[i];
                maxIndex = i;
            }
            if (nums[i] < mini) {
                mini = nums[i];
                minIndex = i;
            }
        }

        int front = max(minIndex, maxIndex) + 1;
        int back = max(n - minIndex, n - maxIndex);
        int both = min(minIndex, maxIndex) + 1 + (n - max(minIndex, maxIndex));

        return min({front, back, both});
    }
};
