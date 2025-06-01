class Solution {
public:
    long long distributeCandies(int n, int limit) {
        long long ways=0;
        int mini=max(0,n-(2*limit));
        int maxi=min(n,limit);
        for(int i=mini;i<=maxi;i++){
            int N=n-i;//remaining
            int minCh2=max(0,N-limit);
            int maxCh2=min(N,limit);
            ways+=maxCh2-minCh2+1;
        }
        return ways;
    }
};
