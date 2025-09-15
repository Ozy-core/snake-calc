#include <iostream>
#include <vector>
#include <string>

using namespace std;

int evaluateGrid(const vector<string>& grid, int row, int col, char currentOp) 
{
    if (col >= grid[row].size()) {
        return 0;
    }

    char ch = grid[row][col];
    int result = 0;

    if (isdigit(ch)) {
        int digit = ch - '0';
        if (currentOp == '+') result += digit;
        else if (currentOp == '-') result -= digit;
        else if (currentOp == '*') result *= digit;
    }
    else if (ch == '+' || ch == '-' || ch == '*') {
        currentOp = ch;
    }
    else if (ch == '^') {
        if (row > 0) {
            result += evaluateGrid(grid, row - 1, col, currentOp);
        }
    }
    else if (ch == 'v') {
        if (row + 1 < grid.size()) {
            result += evaluateGrid(grid, row + 1, col, currentOp);
        }
    }
    return result + evaluateGrid(grid, row, col + 1, currentOp);
}

int main() {
    
    vector<string> grid = {
        "+2v3",
        " ^4*5"
    };

    int total =evaluateGrid(grid, 0, 0, '+');
    cout << "Total: " << total << endl;

    return 0;
}
