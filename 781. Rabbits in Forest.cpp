class Solution {
public:
    int numRabbits(vector<int>& answers) {
        int n = answers.size();
        int ans = 0;
        unordered_map<int, int> count;
        for (auto& num : answers) {
            count[num]++;
            if (num == 0 || (count[num] % (num + 1)) == 1) {
                ans += num + 1;
            }
        }
        return ans;
    }
};
