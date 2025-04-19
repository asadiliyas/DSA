class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        long long ans=0;
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size();i++){
            int idx=lower_bound(nums.begin()+i+1,nums.end(),lower-nums[i])-nums.begin();
            int x=idx-1;
            idx=upper_bound(nums.begin()+i+1,nums.end(),upper-nums[i])-nums.begin();
            int y=idx-1;
            ans+=y-x;
        }
        return ans;
    }
};
