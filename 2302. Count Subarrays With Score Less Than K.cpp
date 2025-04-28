class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        long long n=nums.size();
        long long ans=0;
        long long totalSubarrays=((long long)n*(n+1)/2);
        long long sumGreaterEqual=0;
        int start=0,end=0;
        long long sum=0;
        while(end<n){
            sum+=nums[end];
            while(sum*(end-start+1)>=k){
                sumGreaterEqual+=n-end;
                sum-=nums[start];
                start++;
            }
            end++;
        }
        return totalSubarrays-sumGreaterEqual;
    }
};
