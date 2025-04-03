class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        int n = nums.size();
        long long ans = 0;
        int leftMax=0;
        int maxDiff=0;

        for(int i=0;i<n;i++){
            ans=max(ans,(long long)maxDiff*nums[i]);
            leftMax=max(leftMax,nums[i]);
            maxDiff=max(maxDiff,leftMax-nums[i]);
        }

        return ans;
    }
};
