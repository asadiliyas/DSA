class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& digits) {
        // TC = O(1)
        // SC = O(1)
        int n = digits.size();
        vector<int> result;
        vector<int> count(10, 0);

        for (auto& num : digits)
            count[num]++;

        for (int i = 1; i <= 9; i++) {
            if (count[i] == 0)
                continue;

            count[i]--;
            for (int j = 0; j <= 9; j++) {
                if (count[j] == 0)
                    continue;

                count[j]--;
                for (int k = 0; k <= 8; k += 2) {
                    if (count[k] == 0)
                        continue;

                    count[k]--;
                    int finalNum = (i * 100) + (j * 10) + k;
                    result.push_back(finalNum);
                    count[k]++;
                }
                count[j]++;
            }
            count[i]++;
        }
        return result;
    }
};
