class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {

        // TC: O(n)
        // SC: O(1)

        vector<int> result;
        int n = nums.size();
        int start, end;

        for (int j = 0; j < n; j++) {
            if (nums[j] == key) {
                start = max(0, j - k);
                end = min(n - 1, j + k);

                if (!result.empty() && start <= result.back()) {
                    start = result.back() + 1;
                }

                for (int i = start; i <= end; i++) {
                    result.push_back(i);
                }
            }
        }

        return result;
    }
};
