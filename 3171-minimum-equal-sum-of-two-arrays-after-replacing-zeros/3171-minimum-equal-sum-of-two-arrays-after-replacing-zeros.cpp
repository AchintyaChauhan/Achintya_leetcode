class Solution {
public:
    long long minSum(vector<int>& nums1, vector<int>& nums2) {
        int count1 = 0, count2 = 0;
        long long sum1 = 0, sum2 = 0;

        for (int x : nums1) {
            if (x == 0) count1++;
            else sum1 += x;
        }

        for (int x : nums2) {
            if (x == 0) count2++;
            else sum2 += x;
        }


        long long minSum1 = sum1 + count1 * 1;
        long long minSum2 = sum2 + count2 * 1;

       if(count1==0 && count2==0){
        if(sum1==sum2){
            return sum1;
        }
        else{
            return -1;
        }
       }
       else if(count1==0){
        if(sum2+count2<=sum1){
            return sum1;
        }
        else{
            return -1;
        }
       }
       else if(count2==0){
        if(sum1+count1<=sum2){
            return sum2;
        }
        else{
            return -1;
        }
       }

       return max(minSum1, minSum2);


        
    }
};
