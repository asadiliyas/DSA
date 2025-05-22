class Solution {
public:
    int maxRemoval(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        int Q = queries.size();
        sort(queries.begin(), queries.end());
        priority_queue<int> maxHeap;//storing farthest point from i
        priority_queue<int, vector<int>, greater<int>> past;//past ending query
        int j = 0;
        int queryUsed = 0;
        for (int i = 0; i < n; i++) {
            while (j < Q && queries[j][0] == i) {
                maxHeap.push(queries[j][1]);
                j++;
            }

            nums[i]-=past.size();

            while(nums[i]>0 && !maxHeap.empty() && maxHeap.top()>=i){
                int ending = maxHeap.top();
                maxHeap.pop();
                past.push(ending);
                nums[i]--;
                queryUsed++;
            }

            if(nums[i]>0)
            return -1;

            while(!past.empty() && past.top()<=i){
                past.pop();
            }
        }

        return Q-queryUsed;
    }
};
