class Solution {
public:
    int n,m;
    typedef pair<int, pair<int, int>> P;

    vector<int> dir = {-1, 0, 1, 0, -1}; // URDL

    bool valid(int i, int j) { return i >= 0 && i < n && j >= 0 && j < m; }

    int minTimeToReach(vector<vector<int>>& moveTime) {
        n = moveTime.size();
        m = moveTime[0].size();
        vector<vector<int>> result(n, vector<int>(m, INT_MAX));
        priority_queue<P, vector<P>, greater<P>> pq;
        result[0][0]=0;
        pq.push({0, {0, 0}});
        while (!pq.empty()) {
            int currTime = pq.top().first;
            int x = pq.top().second.first;
            int y = pq.top().second.second;
            pq.pop();

            if (x == n - 1 && y == m - 1)
                return currTime;

            for (int i = 0; i < 4; i++) {
                int newX = x + dir[i];
                int newY = y + dir[i + 1];
                if (valid(newX, newY)){
                    int arrTime=max(currTime,moveTime[newX][newY])+1;
                    if(arrTime<result[newX][newY])
                    {
                        result[newX][newY]=arrTime;
                        pq.push({arrTime,{newX,newY}});
                    }
                }

            }
        }
        return -1;
    }
};
