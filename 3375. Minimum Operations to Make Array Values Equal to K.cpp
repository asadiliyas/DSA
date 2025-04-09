class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        int count=0;
        for(auto& num: nums){
            mp[num]++;
            if(mp[num]==1&&num>k){
                count++;
            }
            if(num<k){
                return -1;
            }
        }
        return count;
    }
};
