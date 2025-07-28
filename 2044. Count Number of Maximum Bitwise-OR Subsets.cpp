class Solution {
public:
    void countSubsets(vector<int>& nums, int& count, int i, int val,
                      int& maxNumPossible) {
        if (i < 0) {
            if (val == maxNumPossible) {
                count++;
            }
            return;
        }

        // skip
        countSubsets(nums, count, i - 1, val, maxNumPossible);

        // take
        val |= nums[i];
        countSubsets(nums, count, i - 1, val, maxNumPossible);
    }

    int countMaxOrSubsets(vector<int>& nums) {

        int n = nums.size();
        int maxNumPossible = 0;

        for (int& num : nums) {
            maxNumPossible |= num;
        }

        int count = 0;

        countSubsets(nums, count, n - 1, 0, maxNumPossible);

        return count;
    }
};
