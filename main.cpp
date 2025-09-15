#include <iostream>
#include <vector>
#include <cctype>

using namespace std;

int applyOp(int total, char op, int num) {
    if (op == '+') return total + num;
    if (op == '-') return total - num;
    if (op == '*') return total * num;
    return total;
}

int evaluateGrid(const vector<string>& grid, int row, int col, int total, char op) {
    if (row < 0 || row >= grid.size() || col >= grid[row].size())
        return total;

    char ch = grid[row][col];

    if (isdigit(ch)) {
        int num = ch - '0';
        total = applyOp(total, op, num);
        return evaluateGrid(grid, row, col + 1, total, op);
    } else if (ch == '+' || ch == '-' || ch == '*') {
        op = ch;
        return evaluateGrid(grid, row, col + 1, total, op);
    } else if (ch == 'v') {
        int branchedTotal = evaluateGrid(grid, row + 1, col, total, op);
        return evaluateGrid(grid, row, col + 1, branchedTotal, op);
    } else if (ch == '^') {
        int branchedTotal = evaluateGrid(grid, row - 1, col, total, op);
        return evaluateGrid(grid, row, col + 1, branchedTotal, op);
    } else {
        return evaluateGrid(grid, row, col + 1, total, op);
    }
}

int main() {
    vector<string> grid = {
        "257*233+6v790-12",
        "61247833212+*9^3"
    };

    int result = evaluateGrid(grid, 0, 0, 0, '+');
    cout << result << endl; 

    return 0;
}
