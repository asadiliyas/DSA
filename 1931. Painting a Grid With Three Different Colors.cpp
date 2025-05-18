class Solution {
public:
    int M = 1e9 + 7;
    vector<string> columnStates;
    vector<vector<int>> t;
    void generateColumnState(string currState, char prevColor, int m) {
        if (currState.size() == m) {
            columnStates.push_back(currState);
            return;
        }

        for (char ch : {'R', 'G', 'B'}) {
            if (ch == prevColor)
                continue;

            generateColumnState(currState + ch, ch, m);
        }
    }

    int solve(int colRemain, int prevIdx, int m) {
        if (colRemain == 0) {
            return 1;
        }

        if (t[colRemain][prevIdx] != -1)
            return t[colRemain][prevIdx];

        int ways = 0;

        string prevState = columnStates[prevIdx];

        for (int i = 0; i < columnStates.size(); i++) {
            if (i == prevIdx)
                continue;

            bool valid = true;
            string currState = columnStates[i];

            for (int j = 0; j < m; j++) {
                if (currState[j] == prevState[j]) {
                    valid = false;
                    break;
                }
            }

            if (valid) {
                ways = (ways + solve(colRemain - 1, i, m)) % M;
            }
        }

        return t[colRemain][prevIdx] = ways;
    }

    int colorTheGrid(int m, int n) {

        generateColumnState("", '#', m);

        int totalColStates = columnStates.size();

        t = vector<vector<int>>(n + 1, vector<int>(totalColStates + 1, -1));

            int result = 0;

        for (int i = 0; i < columnStates.size(); i++) {
            result = (result + solve(n - 1, i, m)) % M;
        }

        return result;
    }
};
