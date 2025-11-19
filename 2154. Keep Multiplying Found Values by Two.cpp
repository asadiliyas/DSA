class Solution {
public:

    // TC = O(n)
    // SC = O(1)

    int findFinalValue(vector<int>& nums, int original) {

        unordered_map<int, bool> mp;

        for (int& num : nums) {
            mp[num] = true;
        }

        int tempOriginal = original;

        while(mp[tempOriginal] == true){
            tempOriginal *= 2;
        }

        return tempOriginal;
    }
};
