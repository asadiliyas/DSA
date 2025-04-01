class Solution {
public:


    long long findPoints(vector<vector<int>>& questions,int n,int index,vector<long long>&dp){

        if(index>=n)
        return 0;

        if(dp[index]!=-1)
        return dp[index];

        //current index not taken
        long long skip = findPoints(questions,n,index+1,dp);

        //current index taken
        long long take = questions[index][0]+findPoints(questions,n,index+questions[index][1]+1,dp);

        return dp[index]=max(skip,take);
    }

    long long mostPoints(vector<vector<int>>& questions) {
        int n=questions.size();
        vector<long long>dp(n,-1);
        long long ans = findPoints(questions,n,0,dp);
        return ans;
    }
};
