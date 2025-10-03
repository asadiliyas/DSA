class Solution {
public:
    typedef pair<int, pair<int, int>> PP;
    vector<int> dir = {-1, 0, 1, 0, -1};

    int trapRainWater(vector<vector<int>>& heightMap) {
        int m = heightMap.size();
        int n = heightMap[0].size();

        priority_queue<PP, vector<PP>, greater<PP>> boundaryCells;

        vector<vector<bool>> visited(m, vector<bool>(n, false));

        // left and right col
        for (int i = 0; i < m; i++) {
            boundaryCells.push({heightMap[i][0], {i, 0}});
            boundaryCells.push({heightMap[i][n - 1], {i, n - 1}});
            visited[i][0] = true;
            visited[i][n - 1] = true;
        }

        // top and bottom row
        for (int i = 1; i < n - 1; i++) {
            boundaryCells.push({heightMap[0][i], {0, i}});
            boundaryCells.push({heightMap[m - 1][i], {m - 1, i}});
            visited[0][i] = true;
            visited[m - 1][i] = true;
        }

        int water = 0;

        while (!boundaryCells.empty()) {
            int height = boundaryCells.top().first;
            int i = boundaryCells.top().second.first;
            int j = boundaryCells.top().second.second;
            boundaryCells.pop();

            for (int k = 0; k < 4; k++) {
                int i_ = i + dir[k];
                int j_ = j + dir[k + 1];

                if (i_ >= 0 && i_ < m && j_ >= 0 && j_ < n &&
                    !visited[i_][j_]) {

                    water += max(0, height - heightMap[i_][j_]);

                    boundaryCells.push(
                        {max(height, heightMap[i_][j_]), {i_, j_}});

                    visited[i_][j_] = true;
                }
            }
        }

        return water;
    }
};
