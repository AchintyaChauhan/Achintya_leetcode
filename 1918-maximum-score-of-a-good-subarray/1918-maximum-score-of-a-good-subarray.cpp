class Solution {
public:
    int maximumScore(vector<int>& nums, int k) {
        int i = k;
        int j = k;
        int n = nums.size();

        int mini = nums[k];
        int sum = mini;  


        while (i > 0 && j < n - 1) {
            if (nums[i - 1] < nums[j + 1]) {
                j++;
            } else {
                i--;
            }
            mini = min({nums[i], mini, nums[j]});
            sum = max(sum, mini * (j - i + 1));
        }
        while (i > 0) {
            i--;
            mini = min(mini, nums[i]);
            sum = max(sum, mini * (j - i + 1));
        }
        while (j < n - 1) {
            j++;
            mini = min(mini, nums[j]);
            sum = max(sum, mini * (j - i + 1));
        }

        return sum;
    }
};
