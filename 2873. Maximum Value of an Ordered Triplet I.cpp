class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        int n=nums.size();
        long long ans=0;
        int maxDiff=0;
        int maxLeft=0;
        for(int k=0;k<n;k++){
            ans=max(ans,(long long)maxDiff*nums[k]);
            maxDiff=max(maxDiff,maxLeft-nums[k]);
            maxLeft=max(maxLeft,nums[k]);
        }
        return ans;
    }
};
