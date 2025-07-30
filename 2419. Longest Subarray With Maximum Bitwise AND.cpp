class Solution {
public:
    int longestSubarray(vector<int>& nums) {

        int n = nums.size();

        int maxNum = 0;

        for (int& num : nums) {
            maxNum = max(maxNum, num);
        }

        int result = 1;

        int currLen = 1;

        for (int i = 1; i < n; i++) {
            if (nums[i] == nums[i - 1] && nums[i] == maxNum) {
                currLen++;
                result = max(result, currLen);
            } else {
                currLen = 1;
            }
        }
        return result;
    }
};
