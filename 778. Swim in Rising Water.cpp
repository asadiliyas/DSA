class Solution {
public:
    vector<int> dir = {-1, 0, 1, 0, -1};
    typedef pair<int, pair<int, int>> PP; // height,{r,c}

    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<bool>> visited(n, vector<bool>(n, false));
        int ans;
        priority_queue<PP, vector<PP>, greater<PP>> p;
        p.push({grid[0][0], {0, 0}});
        visited[0][0] = true;

        while (!p.empty()) {
            int elev = p.top().first;
            int r = p.top().second.first;
            int c = p.top().second.second;
            p.pop();
            if (r == n - 1 && c == n - 1) {
                ans = elev;
                break;
            }

            for (int i = 0; i < 4; i++) {
                int newR = r + dir[i];
                int newC = c + dir[i + 1];
                if (newR >= 0 && newR < n && newC >= 0 && newC < n &&
                    !visited[newR][newC]) {
                    visited[newR][newC] = true;
                    int newElev = grid[newR][newC];
                    p.push({max(elev, newElev), {newR, newC}});
                }
            }
        }

        return ans;
    }
};
