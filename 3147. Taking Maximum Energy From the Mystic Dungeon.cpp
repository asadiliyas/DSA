class Solution {
public:
    int maximumEnergy(vector<int>& energy, int k) {

        int n = energy.size();
        int ans = INT_MIN;
        vector<int> dp(n, 0);

        for (int i = 0; i < n; i++) {

            if (i - k >= 0) {
                dp[i] = max(energy[i], energy[i] + dp[i - k]);
            } else {
                dp[i] = energy[i];
            }

            if (i + k >= n) {
                ans = max(ans, dp[i]);
            }
        }

        return ans;
    }
};
