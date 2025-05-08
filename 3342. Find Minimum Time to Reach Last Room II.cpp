class Solution {
public:
    typedef pair<int, pair<int, pair<int, int>>> P;
    vector<int> dir = {-1, 0, 1, 0, -1};

    int minTimeToReach(vector<vector<int>>& moveTime) {
        int n = moveTime.size();
        int m = moveTime[0].size();
        vector<vector<int>> result(n, vector<int>(m, INT_MAX));
        priority_queue<P, vector<P>, greater<P>> pq;
        pq.push({0, {1, {0, 0}}});
        result[0][0]=0;
        while (!pq.empty()) {
            int currTime = pq.top().first;
            int val = pq.top().second.first;
            int x = pq.top().second.second.first;
            int y = pq.top().second.second.second;
            pq.pop();
            if (x == n - 1 && y == m - 1)
                return currTime;

            for (int i = 0; i < 4; i++) {
                int newX = x + dir[i];
                int newY = y + dir[i + 1];
                if (newX >= 0 && newX < n && newY >= 0 && newY < m) {
                    int arrTime = max(currTime, moveTime[newX][newY]) + val;
                    if (arrTime < result[newX][newY]) {
                        result[newX][newY] = arrTime;
                        int newVal;
                        if (val == 1) {
                            newVal = 2;
                        } else {
                            newVal = 1;
                        }
                        pq.push({arrTime, {newVal, {newX, newY}}});
                    }
                }
            }
        }
        return -1;
    }
};
