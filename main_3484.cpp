#include "bits/stdc++.h"

using namespace std;

class Spreadsheet {
public:

    vector<vector<int>> nums;

    Spreadsheet(int rows) {
        nums.resize(26, vector<int>(rows + 1, 0));
    }

    void setCell(string cell, int value) {
        int r = cell[0] - 'A';
        int c = stoi(cell.substr(1));
        nums[r][c] = value;
    }

    void resetCell(string cell) {
        setCell(cell, 0);
    }

    int getValue(string formula) {
        int row = -1, col = 0, res = 0;
        for (const auto &c: formula) {
            if (c == '=') {
                continue;
            }
            if (c == '+') {
                cout << row << " " << col << endl;
                res += row == -1 ? col : nums[row][col];
                row = -1;
                col = 0;
                continue;
            }
            if ('A' <= c && c <= 'Z') {
                row = c - 'A';
                continue;
            }
            if ('0' <= c && c <= '9') {
                col = 10 * col + (c - '0');
            }
        }
        return res + (row == -1 ? col : nums[row][col]);
    }
};