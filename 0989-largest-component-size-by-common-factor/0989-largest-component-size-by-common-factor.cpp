class Solution {
public:

vector<int> parent;
vector<int> rank;
int find(int x) {
    if(parent[x] == x)
        return x;
    
    return parent[x] = find(parent[x]);
}

void Union(int x, int y) {
    int x_parent = find(x);
    int y_parent = find(y);


    if(rank[x_parent] > rank[y_parent]) {
        parent[y_parent] = x_parent;
    } else if(rank[x_parent] < rank[y_parent]) {
        parent[x_parent] = y_parent;
    } else {
        parent[x_parent] = y_parent;
        rank[y_parent]++;
    }
}
    void reset(int x) {
        parent[x] = x;
        rank[x] = 0;
    }



     vector<int> getf(int x) {
        vector<int> factors;
        for (int i = 2; i * i <= x; ++i) {
            if (x % i == 0) {
                factors.push_back(i);
                while (x % i == 0) x /= i;
            }
        }
        if (x > 1) factors.push_back(x);
        return factors;
    }
    int largestComponentSize(vector<int>& nums) {
        int n=*max_element(nums.begin(),nums.end());
        parent.resize(n+1);
        rank.resize(n+1,0);

        for(int i=0;i<n;i++){
            parent[i]=i;
        }

        for(auto it: nums){
            vector<int>factor=getf(it);
            for(auto f:factor){
                Union(it,f);
            }
        }

        unordered_map<int,int>mpp;
        int ans=0;
        for(auto it:nums){
            int root=find(it);
            mpp[root]++;
        }

        for(auto it:mpp){
            int x=it.second;
            ans=max(ans,x);
        }

        return ans;

         

        
    }
};