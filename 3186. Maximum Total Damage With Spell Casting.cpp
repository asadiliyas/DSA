class Solution {
public:
    long long maximumTotalDamage(vector<int>& power) {
        unordered_map<int, int> mp;
        long long ans = INT_MIN;

        for (int& x : power) {
            mp[x]++;
        }

        vector<int> nums;

        for (auto& it : mp) {
            nums.push_back(it.first);
        }

        int n = nums.size();

        vector<long long> t(n, 0);

        sort(nums.begin(), nums.end());

        for (int i = n - 1; i >= 0; i--) {

            long long skip = (i + 1 >= n) ? 0 : t[i + 1];

            int j = lower_bound(nums.begin() + i + 1, nums.end(), nums[i] + 3) -
                    nums.begin();

            long long take = 1ll * nums[i] * mp[nums[i]] + ((j >= n) ? 0 : t[j]);

            t[i] = max(skip, take);

            ans = max(ans, t[i]);
        }

        return ans;
    }
};
