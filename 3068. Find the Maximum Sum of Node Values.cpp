class Solution {
public:
    long long maximumValueSum(vector<int>& nums, int k,
                              vector<vector<int>>& edges) {
        int n = nums.size();
        int minLoss = INT_MAX;
        int count = 0;
        long long result = 0;
        for (int i = 0; i < n; i++) {
            if ((nums[i] ^ k) > nums[i]) {
                nums[i] = (nums[i] ^ k);
                count++;
            }
            result += nums[i];
            minLoss = min(minLoss, nums[i] - (nums[i] ^ k));
        }

        return count % 2 == 0 ? result : result - minLoss;
    }
};
