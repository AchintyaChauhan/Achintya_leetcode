class Solution {
public:
    int candy(vector<int>& nums) {
        int n=nums.size();
        int count=0;
        vector<int>ans(n,0);
        ans[0]=1;

        for(int i=1;i<n;i++){
            if(nums[i]>nums[i-1]){
                ans[i]=1+ans[i-1];
            }
            else{
                ans[i]=1;
            }
        }
        for(int i=n-2;i>=0;i--){
            if(nums[i]>nums[i+1]){
                // ans[i]=1+ans[i+1];
                ans[i]=max(ans[i],1+ans[i+1]);
            }
            
        }
        for(auto it:ans){
            count+=it;
        }

        return count;

        
    }
};