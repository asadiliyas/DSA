class Solution {
public:
    int maxDifference(string s) {
        vector<int> freq(26, 0);
        int maxOddFreq = INT_MIN;
        int minEvenFreq = INT_MAX;
        for (char& c : s) {
            freq[c - 'a']++;
        }

        for (int& count : freq) {
            if (count != 0 && count % 2 == 0) {
                minEvenFreq = min(minEvenFreq, count);
            } else {
                maxOddFreq = max(maxOddFreq, count);
            }
        }

        return maxOddFreq - minEvenFreq;
    }
};
