class Solution {
public:
    int subsetXORSum(vector<int>& nums) {
        int n = nums.size();
        int result = 0;
        for (int& num : nums) {
            result |= num;
        }
        result = result << (n - 1);
        return result;
    }
};
