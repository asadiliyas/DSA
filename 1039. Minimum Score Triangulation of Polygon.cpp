class Solution {
public:

    // TC = O(n^3) n^2 times function called * n times middle point selected
    // SC = O(n^2) dp vector

    // O(n^2)
    int solve(vector<int>& values, int i, int j, vector<vector<int>>& dp) {
        if (i + 1 == j) {
            return 0;
        }

        if (dp[i][j] != -1) {
            return dp[i][j];
        }

        int ans = INT_MAX;

        // O(n)
        for (int k = i + 1; k < j; k++) {

            ans =
                min(ans, values[i] * values[k] * values[j] +
                             solve(values, i, k, dp) + solve(values, k, j, dp));
        }

        return dp[i][j] = ans;
    }

    int minScoreTriangulation(vector<int>& values) {
        int n = values.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));
        return solve(values, 0, n - 1, dp);
    }
};
