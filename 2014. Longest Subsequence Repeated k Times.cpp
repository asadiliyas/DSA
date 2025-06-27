class Solution {
public:
    bool isSubsequence(string& temp, string& s, int& k) {
        int i = 0;
        int j = 0;
        while (i < temp.size() * k && j < s.size()) {
            if (temp[i % temp.size()] == s[j]) {
                i++;
            }
            j++;
        }

        return i == k * temp.size();
    }

    void backtracking(string& s, string& temp, int& k, vector<bool>& canUse,
                      vector<int>& canTakeFreq, int& maxLength,
                      string& result) {
        if (temp.size() > maxLength) {
            return;
        }

        if (isSubsequence(temp, s, k) &&
            (temp.size() > result.size() ||
             (temp.size() == result.size() && temp > result))) {
            result = temp;
        }

        for (int i = 0; i < 26; i++) {
            if (canUse[i] == false || canTakeFreq[i]==0)
                continue;

            // Do
            char ch = i + 'a';
            temp.push_back(ch);
            canTakeFreq[i]--;

            backtracking(s, temp, k, canUse, canTakeFreq, maxLength, result);
            temp.pop_back();
            canTakeFreq[i]++;
        }
        return;
    }

    string longestSubsequenceRepeatedK(string s, int k) {
        int n = s.size();
        string result;
        vector<int> freq(26, 0);
        for (char& ch : s) {
            freq[ch - 'a']++;
        }

        vector<bool> canUse(26, false);
        vector<int> canTakeFreq(26, 0);

        for (int i = 0; i < 26; i++) {
            if (freq[i] >= k) {
                canUse[i] = true;
                canTakeFreq[i] = freq[i] / k;
            }
        }

        int maxLength = n / k;
        string temp;
        backtracking(s, temp, k, canUse, canTakeFreq, maxLength, result);

        return result;
    }
};
