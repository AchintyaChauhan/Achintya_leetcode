class Solution {
public:
    int numRabbits(vector<int>& nums) {
        unordered_map<int,int>mpp;
        for(int i=0;i<nums.size();i++){
            mpp[nums[i]+1]++;
        }
        int count=0;

        for(auto it:mpp){
            int remaining=(it.second+it.first-1)/it.first;
            int total=remaining*it.first;
            count+=total;
        }

        return count;
    }
};