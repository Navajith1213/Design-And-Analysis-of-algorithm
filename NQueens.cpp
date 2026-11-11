#include <iostream>
#include <vector>
#include <cstdlib>
using namespace std;

int n;
int countSolutions = 0;
vector<int> col;   // col[row] = column of the queen placed in that row

bool isSafe(int row, int c) {
    for (int r = 0; r < row; r++) {
        if (col[r] == c || abs(col[r] - c) == row - r)
            return false;
    }
    return true;
}

void printBoard() {
    countSolutions++;
    cout << "Solution " << countSolutions << ":\n";
    for (int r = 0; r < n; r++) {
        for (int c = 0; c < n; c++)
            cout << (col[r] == c ? 'Q' : '.') << ' ';
        cout << "\n";
    }
    cout << "\n";
}

void solve(int row) {
    if (row == n) {
        printBoard();
        return;
    }
    for (int c = 0; c < n; c++) {
        if (isSafe(row, c)) {
            col[row] = c;
            solve(row + 1);
        }
    }
}

int main() {
    cout << "Enter the board size N: ";
    cin >> n;
    if (n < 1) return 0;

    col.assign(n, -1);
    solve(0);

    cout << "Total solutions: " << countSolutions << "\n";
    if (countSolutions == 0)
        cout << "No solution exists.\n";
    return 0;
}