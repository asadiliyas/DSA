class Solution {
public:
    long long maxSubarrays(int n, vector<vector<int>>& conflictingPairs) {

        vector<vector<int>> adj(n + 1);
        vector<long long> extra(n + 1, 0);
        long long count = 0;

        for (auto& pair : conflictingPairs) {

            int a = min(pair[0], pair[1]);
            int b = max(pair[0], pair[1]);

            adj[b].push_back(a);
        }

        int maxResPoint = 0, secondResPoint = 0;

        for (int i = 1; i <= n; i++) {

            for (int & x : adj[i]) {

                if (x >= maxResPoint) {
                    secondResPoint = maxResPoint;
                    maxResPoint = x;
                }

                else if (x > secondResPoint) {
                    secondResPoint = x;
                }
            }

            count += i - maxResPoint;
            extra[maxResPoint] += maxResPoint - secondResPoint;
        }

        long long maxExtra = INT_MIN;

        for (int i = 1; i <= n; i++) {
            maxExtra = max(maxExtra, extra[i]);
        }

        return count + maxExtra;
    }
};
