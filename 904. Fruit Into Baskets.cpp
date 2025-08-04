class Solution {
public:
    int totalFruit(vector<int>& fruits) {

        int n = fruits.size();
        int result = 0;
        unordered_map<int, int> mp;//last occurence of each num

        int left = 0;
        int i = 0;

        while (i < n) {

            mp[fruits[i]] = i;

            if (mp.size() > 2) {

                result = max(result, i - left);

                int smallerIdx = INT_MAX;

                for (const auto& pair : mp) {

                    int idx = pair.second;

                    smallerIdx = min(smallerIdx, idx);//smaller last occurence

                }

                mp.erase(fruits[smallerIdx]);
                left = smallerIdx + 1;
            }

            i++;
        }

        result = max(result, i - left);

        return result == 0 ? n : result;
    }
};
