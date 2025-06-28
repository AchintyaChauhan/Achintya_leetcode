class Solution {
public:


    static bool comp(pair<int, int>& a, pair<int, int>& b) {
        return a.second < b.second;
    }
    
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        vector<pair<int, int>> temp;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            temp.push_back({nums[i], i});
        }

        sort(temp.rbegin(), temp.rend());
        temp.resize(k);
        sort(temp.begin(), temp.end(), comp);

        vector<int> ans;
        for (auto it : temp) {
            ans.push_back(it.first);
        }

        return ans;
    }
};
