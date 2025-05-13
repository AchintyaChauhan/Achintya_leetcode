class Solution {
public:
    const int mod = 1e9 + 7;

    int lengthAfterTransformations(string s, int t) {
        vector<int> freq(26, 0);

        for (char ch : s) {
            freq[ch - 'a']++;
        }

        for (int step = 1; step <= t; ++step) {
            vector<int> nextFreq(26, 0);
            for (int i = 0; i < 26; ++i) {
                if (freq[i] == 0) continue;

                if (i != 25) {
                    nextFreq[i + 1] = (nextFreq[i + 1] + freq[i]) % mod;
                } else {
                    nextFreq[0] = (nextFreq[0] + freq[i]) % mod;
                    nextFreq[1] = (nextFreq[1] + freq[i]) % mod;
                }
            }
            freq = move(nextFreq);
        }

        int ans = 0;
        for (int i = 0; i < 26; ++i) {
            ans = (ans + freq[i]) % mod;
        }

        return ans;
    }
};
