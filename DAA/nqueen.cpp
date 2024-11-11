#include <iostream>
#include <vector>
using namespace std;

bool isSafe(vector<vector<int>>& board, int row, int col, int N) {
    // Check this row on the left side
    for (int i = 0; i < col; i++)
        if (board[row][i] == 1)
            return false;

    // Check upper diagonal on the left side
    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--)
        if (board[i][j] == 1)
            return false;

    // Check lower diagonal on the left side
    for (int i = row, j = col; j >= 0 && i < N; i++, j--)
        if (board[i][j] == 1)
            return false;

    return true;
}

bool solveNQueensUtil(vector<vector<int>>& board, int col, int N) {
    if (col >= N) // All queens are placed
        return true;

    for (int i = 0; i < N; i++) {
        if (isSafe(board, i, col, N)) {
            board[i][col] = 1; // Place queen

            if (solveNQueensUtil(board, col + 1, N)) // Recursively place rest of the queens
                return true;

            board[i][col] = 0; // Backtrack
        }
    }
    return false;
}

void printSolution(vector<vector<int>>& board, int N) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++)
            cout << (board[i][j] == 1 ? "Q " : "- ");
        cout << endl;
    }
}

void solveNQueens(int N) {
    vector<vector<int>> board(N, vector<int>(N, 0));

    if (!solveNQueensUtil(board, 0, N)) {
        cout << "Solution does not exist" << endl;
        return;
    }

    printSolution(board, N);
}

int main() {
    int N;
    cout << "Enter the number of queens: ";
    cin >> N;
    solveNQueens(N);
    return 0;
}


// Time Complexity:
// O(N³): The algorithm checks each of the N rows for each of the N columns, and for each placement, it performs O(N) checks for safety.
// Space Complexity:
// O(N²): The 2D board requires O(N²) space, and the recursion stack requires O(N) space.