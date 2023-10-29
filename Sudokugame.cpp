#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

// Define the size of the Sudoku grid
const int N = 9;
const int EMPTY = 0;

// Function to print the Sudoku grid
void printGrid(const std::vector<std::vector<int>>& grid) {
    for (int i = 0; i < N; i++) {
        if (i % 3 == 0 && i != 0) {
            std::cout << "-------------------------" << std::endl;
        }
        for (int j = 0; j < N; j++) {
            if (j % 3 == 0 && j != 0) {
                std::cout << "| ";
            }
            std::cout << grid[i][j] << ' ';
        }
        std::cout << std::endl;
    }
}

// Function to check if a number is safe to place in the grid
bool isSafe(std::vector<std::vector<int>>& grid, int row, int col, int num) {
    // Check row and column
    for (int i = 0; i < N; i++) {
        if (grid[row][i] == num || grid[i][col] == num) {
            return false;
        }
    }

    // Check 3x3 subgrid
    int startRow = row - row % 3;
    int startCol = col - col % 3;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (grid[i + startRow][j + startCol] == num) {
                return false;
            }
        }
    }

    return true;
}

// Function to solve the Sudoku puzzle using backtracking
bool solveSudoku(std::vector<std::vector<int>>& grid) {
    for (int row = 0; row < N; row++) {
        for (int col = 0; col < N; col++) {
            if (grid[row][col] == EMPTY) {
                for (int num = 1; num <= N; num++) {
                    if (isSafe(grid, row, col, num)) {
                        grid[row][col] = num;
                        if (solveSudoku(grid)) {
                            return true;
                        }
                        grid[row][col] = EMPTY;
                    }
                }
                return false;
            }
        }
    }
    return true;
}

// Function to generate a Sudoku puzzle
void generateSudoku(std::vector<std::vector<int>>& grid) {
    // Initialize the random number generator
    srand(time(nullptr));

    // Fill the grid with a solved Sudoku puzzle
    solveSudoku(grid);

    // Remove some numbers to create a puzzle
    int numToRemove = N * N / 2; // You can adjust this number to control the puzzle difficulty
    while (numToRemove > 0) {
        int row = rand() % N;
        int col = rand() % N;
        if (grid[row][col] != EMPTY) {
            grid[row][col] = EMPTY;
            numToRemove--;
        }
    }
}

int main() {
    std::vector<std::vector<int>> grid(N, std::vector<int>(N, EMPTY));
    generateSudoku(grid);

    std::cout << "Sudoku Puzzle:" << std::endl;
    printGrid(grid);

    // You can add code here to allow the user to play the game.

    return 0;
}
