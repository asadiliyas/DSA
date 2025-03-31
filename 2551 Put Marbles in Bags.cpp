class Solution {
    public:
        long long putMarbles(vector<int>& weights, int k) {
            int n=weights.size();
            vector<int>pairSum;
            for(int i=0;i<n-1;i++){
                int sum=weights[i]+weights[i+1];
                pairSum.push_back(sum);
            }
            sort(pairSum.begin(),pairSum.end());
            long long minSum=0;
            for(int i=0;i<k-1;i++){
                minSum+=pairSum[i];
            }
            long long maxSum=0;
            int m=pairSum.size();
            int i=m-1;
            int count=k-1;
            while(count--){
                maxSum+=pairSum[i];
                i--;
            }
            return maxSum-minSum;
        }
    };
