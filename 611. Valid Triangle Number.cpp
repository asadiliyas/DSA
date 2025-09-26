class Solution {
public:
    int triangleNumber(vector<int>& nums) {

        // TC = O(n2)
        // SC = O(1)

        int n = nums.size();

        sort(nums.begin(), nums.end());

        int ans = 0;

        for (int k = n - 1; k >= 2; k--) {
            int i = 0;
            int j = k - 1;

            while (i < j) {
                if (nums[i] + nums[j] <= nums[k]) {
                    i++;
                } else {

                    ans += j - i;
                    j--;
                }
            }
        }

        return ans;
    }
};
