class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        long long result = 0;
        int maxElement = INT_MIN;
        for (int& num : nums) {
            maxElement = max(maxElement, num);
        }

        vector<int>indices;
        for(int i=0;i<n;i++){
            if(nums[i]==maxElement){
                indices.push_back(i);
            }

            if(indices.size()>=k){
                result+=indices[indices.size()-k]+1;
            }
        }
        
        return result;
    }
};
