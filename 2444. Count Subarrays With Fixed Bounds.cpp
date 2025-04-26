class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        int n = nums.size();
        int minIdx = -1;
        int maxIdx = -1;
        int culIdx = -1;
        long long ans = 0;
        for (int i = 0; i < n; i++) {
            if (nums[i] == minK)
                minIdx = i;
            if (nums[i] == maxK)
                maxIdx = i;

            if (nums[i] < minK || nums[i] > maxK)
                culIdx = i;

            int smaller = min(minIdx, maxIdx);

            int temp = smaller - culIdx;

            ans += temp <= 0 ? 0 : temp;
        }
        return ans;
    }
};
