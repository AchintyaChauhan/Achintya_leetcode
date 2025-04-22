class Solution {
public:
    bool ispossible(string s1, string s2, int n, int m){
        int i = 0, j = 0;
        while(i < n && j < m){
            if(s1[i] == s2[j]){
                j++;
            }
            i++;
        }
        return j == m;
    }

    int numMatchingSubseq(string s, vector<string>& words) {
        unordered_map<string, bool> mpp;
        int count = 0;

        for(auto it : words){
            if(mpp.find(it) != mpp.end()){
                if(mpp[it]) count++;
                continue;
            }

            mpp[it] = ispossible(s, it, s.size(), it.size());
            if(mpp[it]) count++;
        }

        return count;
    }
};
