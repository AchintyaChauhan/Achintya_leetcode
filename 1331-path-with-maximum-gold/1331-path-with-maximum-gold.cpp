class Solution {
public:
int n;
int m;

    int solve(int i, int j,vector<vector<int>>& grid ){
        if(i>=n|| i<0 || j>=m || j<0 || grid[i][j]==0){
            return 0;
        }
        int og=grid[i][j];

        grid[i][j]=0;

        int maxi=0;

        maxi=max(maxi,solve(i-1,j,grid));
        maxi=max(maxi,solve(i+1,j,grid));
        maxi=max(maxi,solve(i,j-1,grid));
        maxi=max(maxi,solve(i,j+1,grid));



        grid[i][j]=og;

        return maxi+og;
    }
    int getMaximumGold(vector<vector<int>>& grid) {
        n=grid.size();
        m=grid[0].size();
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]!=0){
                    ans=max(ans,solve(i,j,grid));
                }
            }
        }

        return ans;
        
    }
};