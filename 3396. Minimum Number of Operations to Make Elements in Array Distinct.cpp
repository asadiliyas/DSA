class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int n = nums.size();
        int index = -1;
        unordered_map<int, int> mp;
        for (int i = n - 1; i >= 0; i--) {
            mp[nums[i]]++;
            if (mp[nums[i]] == 2) {
                index=i;
                break;
            }
        }

        return index == -1 ? 0 : (index / 3) + 1;
    }
};
