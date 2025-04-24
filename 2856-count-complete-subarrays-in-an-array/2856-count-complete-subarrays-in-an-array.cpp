class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        int n=nums.size();
        int i=0;
        int j=0;
        int count=0;
        unordered_set<int>st(nums.begin(),nums.end());
        unordered_map<int,int>mpp;
        while(j<n){
            mpp[nums[j]]++;
            while(mpp.size()==st.size()){
                count+=n-j;
                mpp[nums[i]]--;
                if(mpp[nums[i]]==0){
                    mpp.erase(nums[i]);
                }
                i++;

            }
            j++;
        }

        return count;
        
    }
};