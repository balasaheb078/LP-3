#include <iostream>
using namespace std;

// Function to check if placing a queen at position (x, y) is safe
bool isSafe(int **arr, int x, int y, int n){
    // Check the column
    for(int row = 0; row < x; row++){
        if(arr[row][y] == 1){
            return false;  // Another queen is placed in the same column
        }
    }

    // Check upper left diagonal
    int row = x, col = y;
    while(row >= 0 && col >= 0){
        if(arr[row][col] == 1){
            return false;  // Another queen is placed in the upper left diagonal
        }
        row--;
        col--;
    }

    // Check upper right diagonal
    row = x;
    col = y;
    while(row >= 0 && col < n){
        if(arr[row][col] == 1){
            return false;  // Another queen is placed in the upper right diagonal
        }
        row--;
        col++;
    }

    return true;  // Safe to place the queen
}

// Function to print the board configuration
void printBoard(int **arr, int n){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(arr[i][j] == 1)
                cout << "[Q] ";  // Queen placed
            else
                cout << "[ ] ";  // Empty space
        }
        cout << endl;
    }
    cout << endl;
}

// Backtracking function to place queens
bool nQueen(int **arr, int x, int n){
    // If all queens are placed, print the solution
    if(x == n){
        printBoard(arr, n);
        return true;
    }

    // Try placing a queen in each column of the current row
    for(int col = 0; col < n; col++){
        if(isSafe(arr, x, col, n)){
            arr[x][col] = 1;  // Place queen at (x, col)

            // Recur to place the next queen
            if(nQueen(arr, x + 1, n)){
                return true;
            }

            // Backtrack: remove the queen and try the next column
            arr[x][col] = 0;
        }
    }

    return false;  // If no safe position found in this row
}

int main(){
    int n = 8;  // Fixed size of the board for 8 Queens problem

    int **arr = new int*[n];  // Create a 2D array to represent the board
    for(int i = 0; i < n; i++){
        arr[i] = new int[n];
        for(int j = 0; j < n; j++){
            arr[i][j] = 0;  // Initialize the board with 0 (no queen placed)
        }
    }

    int firstQueenColumn;
    cout << "Enter the column (0-indexed) to place the first queen in the first row: ";
    cin >> firstQueenColumn;

    // Validate the first queen's position
    if(firstQueenColumn >= 0 && firstQueenColumn < n){
        arr[0][firstQueenColumn] = 1;

        // Check if the initial placement leads to any solution
        if(!nQueen(arr, 1, n)){
            cout << "No solution found after placing the first queen at (0, " << firstQueenColumn << ")." << endl;
        }
    } else {
        cout << "Invalid column for the first queen. Please try again with a valid column (0 to " << n-1 << ")." << endl;
    }

    // Deallocate memory
    for(int i = 0; i < n; i++){
        delete[] arr[i];
    }
    delete[] arr;

    return 0;
}

/*
Time Complexity: O(N!)
    - There are N rows, and for each row, there are N possible columns to place a queen. 
    - The recursive calls explore all possible combinations of queen placements.
Auxiliary Space: O(N^2)
    - The space required to store the N x N board.
*/