class Solution {
public:
    bool makeSubsets(vector<int>& nums, int remainingSum, int i, int n,
                     vector<vector<int>>& t) {

        if (remainingSum == 0) {
            return true;
        }

        if (i == n) {
            return false;
        }

        if (t[i][remainingSum] != -1) {
            return t[i][remainingSum];
        }

        bool skip = makeSubsets(nums, remainingSum, i + 1, n, t);
        bool take = false;
        if (remainingSum - nums[i] >= 0) {
            take = makeSubsets(nums, remainingSum - nums[i], i + 1, n, t);
        }

        return t[i][remainingSum] = skip || take;
    }

    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int totalSum = 0;
        for (auto& num : nums) {
            totalSum += num;
        }

        if (totalSum % 2 == 1)
            return false;

        vector<vector<int>> t(n + 1, vector<int>(totalSum + 1, -1));

        return makeSubsets(nums, totalSum / 2, 0, n, t);
    }
};
