class Solution {
public:
    int minDeletions(string s) {
        vector<int> nums(26, 0);  
        for (char ch : s) {
            nums[ch - 'a']++;
        }

        unordered_set<int> st;
        int count = 0;
        sort(nums.rbegin(), nums.rend()); 

        for (int i = 0; i < nums.size(); i++) {
            while (nums[i] > 0 && st.find(nums[i]) != st.end()) {
                nums[i]--;
                count++;
            }
            if (nums[i] > 0) {
                st.insert(nums[i]);
            }
        }

        return count;
    }
};
