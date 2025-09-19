class Spreadsheet {
public:
    vector<vector<int>> spreadsheet;

    Spreadsheet(int rows) {
        spreadsheet = vector<vector<int>>(rows + 1, vector<int>(26, 0));
    }

    void setCell(string cell, int value) {
        int row = stoi(cell.substr(1));
        int col = cell[0] - 'A';
        spreadsheet[row][col] = value;
    }

    void resetCell(string cell) {
        int row = stoi(cell.substr(1));
        int col = cell[0] - 'A';
        spreadsheet[row][col] = 0;
    }

    int getValue(string formula) {
        string first = "";
        int idx = 1;
        while (formula[idx] != '+') {
            first += formula[idx];
            idx++;
        }

        int firstNum;

        if (first[0] >= 'A' && first[0] <= 'Z') {
            int col = first[0] - 'A';
            int row = stoi(first.substr(1));
            firstNum = spreadsheet[row][col];
        }

        else {
            firstNum = stoi(first);
        }

        string second = "";
        idx++;
        while (idx < formula.size()) {
            second += formula[idx];
            idx++;
        }

        int secondNum;

        if (second[0] >= 'A' && second[0] <= 'Z') {
            int col = second[0] - 'A';
            int row = stoi(second.substr(1));
            secondNum = spreadsheet[row][col];
        }

        else {
            secondNum = stoi(second);
        }

        return firstNum + secondNum;
    }
};

/**
 * Your Spreadsheet object will be instantiated and called as such:
 * Spreadsheet* obj = new Spreadsheet(rows);
 * obj->setCell(cell,value);
 * obj->resetCell(cell);
 * int param_3 = obj->getValue(formula);
 */
