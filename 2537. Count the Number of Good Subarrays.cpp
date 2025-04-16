class Solution {
public:
    long long countGood(vector<int>& nums, int k) {
        int n=nums.size();
        int start=0,end=0;
        long long ans=0;
        long long pairs=0;
        unordered_map<int,int>mp;
        while(end<n){
            pairs+=mp[nums[end]];
            mp[nums[end]]++;
            while(pairs>=k){
                ans+=n-end;
                mp[nums[start]]--;
                pairs-=mp[nums[start]];
                start++;
            }
            end++;
        }

        return ans;
    }
};
