class Solution {
public:
    int m, n;
    vector<int> dir = {-1, 0, 1, 0, -1};

    void solve(vector<vector<int>>& heights, bool& pacific, bool& atlantic,
               int r, int c, vector<vector<bool>>& visited) {
        if (r == 0 || c == 0) {
            pacific = true;
        }

        if (r == m - 1 || c == n - 1) {
            atlantic = true;
        }

        if (pacific == true && atlantic == true) {
            return;
        }

        visited[r][c] = true;

        for (int i = 0; i < 4; i++) {
            int newR = r + dir[i];
            int newC = c + dir[i + 1];

            if (newR >= 0 && newR < m && newC >= 0 && newC < n &&
                heights[r][c] >= heights[newR][newC] && !visited[newR][newC]) {
                visited[newR][newC] = true;
                solve(heights, pacific, atlantic, newR, newC, visited);
            }
        }
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        m = heights.size();
        n = heights[0].size();
        vector<vector<int>> ans;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                bool pacific = false, atlantic = false;
                vector<vector<bool>> visited(m, vector<bool>(n, false));
                solve(heights, pacific, atlantic, i, j, visited);

                if (pacific == true && atlantic == true) {
                    ans.push_back({i, j});
                }
            }
        }

        return ans;
    }
};
