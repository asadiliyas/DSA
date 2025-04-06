class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<int> dp(n, 1);
        vector<int> prev_idx(n, -1);
        int lastIndex = 0;
        int maxLen = 1;

        for (int i = 1; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (nums[i] % nums[j] == 0) {
                    if (dp[i] < dp[j] + 1) {
                        dp[i] = dp[j] + 1;
                        prev_idx[i] = j;
                    }
                    if (dp[i] > maxLen) {
                        maxLen = dp[i];
                        lastIndex = i;
                    }
                }
            }
        }
        vector<int> res;
        while (lastIndex != -1) {
            res.push_back(nums[lastIndex]);
            lastIndex = prev_idx[lastIndex];
        }
        return res;
    }
};
