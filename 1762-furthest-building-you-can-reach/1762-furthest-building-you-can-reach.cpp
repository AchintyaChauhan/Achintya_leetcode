class Solution {
public:
    int furthestBuilding(vector<int>& nums, int b, int l) {
        int n = nums.size();
        priority_queue<int> pq;

        for (int i = 0; i < n - 1; i++) {
            int diff = nums[i + 1] - nums[i];

            if (diff > 0) {
                if (b >= diff) {
                    b -= diff;
                    pq.push(diff);
                }
                else if (l > 0) {
                    if (!pq.empty() && pq.top() > diff) {
                        b += pq.top() - diff;
                        pq.pop();
                        pq.push(diff);
                    }
                    // Whether you swap or not, you're using a ladder:
                    l--;
                }
                else {
                    return i;
                }
            }
        }

        return n - 1;
    }
};
