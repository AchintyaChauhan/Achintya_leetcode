class Solution {
public:
    int maximumPossibleSize(vector<int>& nums) {
        int prev = -1; 
        int size = 0; 
        for (int num : nums) {
            if (num >= prev) {
                prev = num;
                size++;
             }
         }
        return size;
    }
};