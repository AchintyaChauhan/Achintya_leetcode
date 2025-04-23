class Solution {
public:
    int countLargestGroup(int n) {
         unordered_map<int, int> mpp;

        for (int i = 1; i <= n; ++i) {
            int sum = 0, num = i;
            while (num > 0) {
                sum += num % 10;
                num /= 10;
            }
        mpp[sum]++;
        }

        int maxi=0;
        for(auto it:mpp){
            maxi=max(maxi,it.second);
        }
        int ans=0;
        for(auto it:mpp){
            if(it.second==maxi){
                ans++;
            }
        }

        return ans;
        
    }
};