class Solution {
public:
    // TC = O(N) traversing nums
    // SC = O(1) no space used
    bool kLengthApart(vector<int>& nums, int k) {
        int n = nums.size();
        int lastIndexOf1 = -1;
        for (int i = 0; i < n; i++) {
            if (nums[i] == 1) {
                if (i - lastIndexOf1 - 1 < k && lastIndexOf1 != -1) {
                    return false;
                }
                lastIndexOf1 = i;
            }
        }
        return true;
    }
};
