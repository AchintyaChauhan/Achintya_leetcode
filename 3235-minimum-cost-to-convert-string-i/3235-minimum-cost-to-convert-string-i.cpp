class Solution {
public:

void floyd(vector<vector<long long>>&adj,vector<char>& og, vector<char>& change, vector<int>& cost){
    for(int i=0;i<og.size();i++){
        int u=og[i]-'a';
        int v=change[i]-'a';
        int w=cost[i];

        adj[u][v]=min(adj[u][v],(long long)cost[i]);

    }
        // F_W


        for(int k=0;k<26;k++){
            for(int i=0;i<26;i++){
                for(int j=0;j<26;j++){
                    adj[i][j]=min(adj[i][j], adj[i][k]+adj[k][j]);


                }
            }
        }
    



}
long long minimumCost(string source, string target, vector<char>& og, vector<char>& change, vector<int>& cost) {

        vector<vector<long long>>adj(26,vector<long long>(26,INT_MAX));

        floyd(adj,og,change,cost);
        long long ans=0;

        for(int i=0;i<source.length();i++){
            if(source[i]==target[i]){
                continue;
            }
            if(adj[source[i]-'a'][target[i]-'a']==INT_MAX){
                return -1;
            }

            ans+=adj[source[i]-'a'][target[i]-'a'];

        }

        return ans;
        
    }
};