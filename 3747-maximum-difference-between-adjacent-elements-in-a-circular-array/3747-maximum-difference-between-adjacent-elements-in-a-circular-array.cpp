class Solution {
public:
    int maxAdjacentDistance(vector<int>& nums) {
        int n=nums.size();
        int extra=abs(nums[0]-nums[n-1]);
        int maxi=extra;

        for(int i=1;i<n;i++){
            maxi=max(maxi, abs(nums[i]-nums[i-1]));
        }

        return maxi;
    }
};