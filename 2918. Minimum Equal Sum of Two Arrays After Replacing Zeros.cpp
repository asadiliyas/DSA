class Solution {
public:
    long long minSum(vector<int>& nums1, vector<int>& nums2) {
        long long minSum1 = 0;
        long long minSum2 = 0;
        int zeroCount1 = 0;
        int zeroCount2 = 0;
        for (auto& num : nums1) {
            if (num == 0) {
                minSum1 += 1;
                zeroCount1++;
            } else
                minSum1 += num;
        }
        for (auto& num : nums2) {
            if (num == 0) {
                minSum2 += 1;
                zeroCount2++;
            } else
                minSum2 += num;
        }

        if(minSum1>minSum2 && zeroCount2!=0){
            return minSum1;
        }

        if(minSum2>minSum1 && zeroCount1!=0){
            return minSum2;
        }

        if(minSum1==minSum2)
        return minSum1;

        return -1;
    }
};
