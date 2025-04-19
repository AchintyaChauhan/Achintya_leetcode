class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        sort(nums.begin(),nums.end());
        int i=0;
        int j=nums.size()-1;
        long long ucount=0;
        while(i<j){
            if(nums[i]+nums[j]<=upper){
                ucount+=j-i;
                i++;
            }
            else{
                j--;
            }
        }

        i=0;
        j=nums.size()-1;
        long long bcount=0;
        while(i<j){
            if(nums[i]+nums[j]<lower){
                bcount+=(j-i);
                i++;
            }
            else{
                j--;
            }
        }

return ucount-bcount;
        
    }
};