class Solution {
public:
    int largestPerimeter(vector<int>& nums) {

        // TC = O(NlogN)
        // SC = O(1)

        int n = nums.size();
        int maxPerimeter = 0;

        sort(nums.begin(), nums.end());

        for (int i = n - 1; i >= 2; i--) {
            if (nums[i - 2] + nums[i - 1] > nums[i]) {
                maxPerimeter = nums[i - 2] + nums[i - 1] + nums[i];
                break;
            }
        }

        return maxPerimeter;
    }
};
