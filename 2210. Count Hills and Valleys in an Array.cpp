class Solution {
public:
    int countHillValley(vector<int>& nums) {
        int n = nums.size();
        int countHillValley = 0;
        vector<int> rightNonEqualNeighbour(n, -1);
        int currDiffNeighbour = nums[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            if (nums[i] == nums[i + 1]) {
                rightNonEqualNeighbour[i] = currDiffNeighbour;
            } else {
                currDiffNeighbour = nums[i + 1];
                rightNonEqualNeighbour[i] = currDiffNeighbour;
            }
        }

        int currLeftDiffNeighbour = nums[0];

        for (int i = 1; i < n-1 ; i++) {
            if (nums[i] != nums[i - 1]) {
                currLeftDiffNeighbour = nums[i - 1];
            }

            if(nums[i] == nums[i - 1]){
                continue;
            }

            if (currLeftDiffNeighbour < nums[i] &&
                nums[i] > rightNonEqualNeighbour[i]) {
                countHillValley++;
            }

            if (currLeftDiffNeighbour > nums[i] &&
                nums[i] < rightNonEqualNeighbour[i]) {
                countHillValley++;
            }
        }
        return countHillValley;
    }
};
