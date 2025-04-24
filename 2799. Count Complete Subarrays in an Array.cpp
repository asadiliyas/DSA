class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        int n = nums.size();
        int uniqueElements = 0;
        int ans = 0;
        unordered_map<int, int> mp;
        for (int& num : nums) {
            mp[num]++;
            if (mp[num] == 1)
                uniqueElements++;
        }

        unordered_map<int, int> mp2;
        int start = 0, end = 0;
        int currUnique = 0;
        while (end < n) {
            mp2[nums[end]]++;
            if (mp2[nums[end]] == 1)
                currUnique++;

            while (currUnique == uniqueElements) {
                ans += n - end;
                mp2[nums[start]]--;
                if (mp2[nums[start]] == 0)
                    currUnique--;

                start++;
            }
            end++;
        }
        return ans;
    }
};
