class Solution {
public:
    int maxSum(vector<int>& nums) {
        int n = nums.size();
        int maxSum = 0;
        unordered_map<int, int> mp;
        int maxNonPos = INT_MIN;
        for (int i = 0; i < n; i++) {
            if (nums[i] <= 0) {
                maxNonPos = max(maxNonPos,nums[i]);
                continue;
            }

            if (!mp.count(nums[i])) {
                maxSum += nums[i];
                mp[nums[i]]++;
            }
        }
        return maxSum == 0 ? maxNonPos : maxSum;
    }
};
