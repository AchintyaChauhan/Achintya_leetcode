class Solution {
public:
    long long largestPerimeter(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        long long sum = 0, res = -1;
        for (int i = 0; i < arr.size(); ++i) {
            if (i >= 2 && arr[i] < sum) {
                res = sum + arr[i]; 
            }
            sum += arr[i];
        }
        return res;
    }
};
