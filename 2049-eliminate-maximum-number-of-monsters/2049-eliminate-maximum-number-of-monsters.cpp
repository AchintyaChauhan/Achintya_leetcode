class Solution {
public:
    int eliminateMaximum(vector<int>& dist, vector<int>& speed) {
        int n=dist.size();
        vector<int>ans(n,0);
        for(int i=0;i<n;i++){
            ans[i]=ceil((float)dist[i]/(float)speed[i]);
        }

        sort(ans.begin(),ans.end());
        int kill=0;
        int time=0;

        for(int i=0;i<n;i++){
            if(time+1>ans[i]){
                break;
            }
            else{
                kill++;
                time++;
            }
        }

        return kill;


        
    }
};