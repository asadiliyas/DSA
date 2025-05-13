class Solution {
public:
    int M = 1e9 + 7;

    int lengthAfterTransformations(string s, int t) {
        vector<long long> freq(26, 0);
        for (char& c : s) {
            freq[c - 'a']++;
        }

        while (t--) {
            vector<long long> freq_(26, 0);
            for (int i = 0; i < 26; i++) {
                if (freq[i] == 0)
                    continue;

                if (i == 25) {
                    freq_[0] = (freq_[0] + freq[i]) % M;
                    freq_[1] = (freq_[1] + freq[i]) % M;
                } else {
                    freq_[i + 1] = (freq_[i + 1] + freq[i]) % M;
                }
            }
            freq = freq_;
        }

        int ans = 0;

        for (int i = 0; i < 26; i++) {
            ans =(ans+freq[i]) % M;
        }
        return ans % M;
    }
};
