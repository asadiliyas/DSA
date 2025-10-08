class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions,
                                long long success) {

        vector<int> ans;
        int m = potions.size();
        sort(begin(potions), end(potions));

        for (int& spell : spells) {
            int start = 0, end = m-1;
            int index = m;

            while (start <= end) {

                int mid = start + (end - start) / 2;

                if ((long long)spell * (long long)potions[mid] >= success) {
                    index = mid;
                    end = mid - 1;
                } else {
                    start = mid + 1;
                }
            }

            ans.push_back(m - index);
        }

        return ans;
    }
};
