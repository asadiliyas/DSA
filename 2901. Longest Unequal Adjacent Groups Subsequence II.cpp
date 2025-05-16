class Solution {
public:
    int hammingDistance(string& s1, string& s2) {
        int count = 0;
        for (int i = 0; i < s1.size(); i++) {
            if (s1[i] != s2[i])
                count++;
        }
        return count;
    }

    vector<string> getWordsInLongestSubsequence(vector<string>& words,
                                                vector<int>& groups) {
        // Longest Increasing Subsequence
        int n = words.size();
        vector<string> result;
        vector<int> dp(n, 1); // LIS till that index
        vector<int> parent(n, -1);
        int indexLIS = 0;
        int maxLIS=0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (words[j].size() == words[i].size() &&
                    groups[j] != groups[i] &&
                    hammingDistance(words[j], words[i]) == 1) {
                    if (dp[i] < dp[j] + 1) {
                        dp[i] = dp[j] + 1;
                        parent[i] = j;
                        if(dp[i]>maxLIS){
                            indexLIS = i;
                            maxLIS=dp[i];
                        }
                    }
                }
            }
        }

        while (indexLIS != -1) {
            result.push_back(words[indexLIS]);
            indexLIS = parent[indexLIS];
        }

        reverse(result.begin(), result.end());
        return result;
    }
};
