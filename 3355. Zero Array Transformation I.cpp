class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n=nums.size();
        vector<int>diffArr(n,0);
        for(int i=0;i<queries.size();i++){
            int start=queries[i][0];
            int end=queries[i][1];
            diffArr[start]+=1;
            if(end+1<n)
            diffArr[end+1]-=1;
        }
        int cumSum=0;
        vector<int>result(n);
        for(int i=0;i<nums.size();i++){
            cumSum+=diffArr[i];
            result[i]=cumSum;
        }

        for(int i=0;i<nums.size();i++){
            if(nums[i]>result[i])
            return false;
        }

        return true;
    }
};
