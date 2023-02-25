#include <bits/stdc++.h>
using namespace std;

bool isSafe(int row, int col, vector<vector<int>> &board, int val)
{
    for (int i = 0; i < board.size(); i++)
    {
        // row & col check
        if (board[row][i] == val || board[i][col] == val)
        {
            return false;
        }
        // 3x3 matrix check
        if (board[3 * (row / 3) + i / 3][3 * (col / 3) + i % 3] == val)
            return false;
    }
    return true;
}

bool solve(vector<vector<int>> &board)
{
    int n = board[0].size();

    for (int row = 0; row < n; row++)
    {
        for (int col = 0; col < n; col++)
        {
            // Is cell empty
            if (board[row][col] == 0)
            {
                for (int val = 1; val <= 9; val++)
                {
                    if (isSafe(row, col, board, val))
                    {
                        board[row][col] = val;

                        // recursive call
                        bool further_sol_pos = solve(board);
                        if (further_sol_pos)
                        {
                            return true;
                        }
                        else
                        {
                            // backtrack
                            board[row][col] = 0; // revert back to original val
                        }
                    }
                }
                return false; // It means that, no value between 1-9 can be inserted
            }
        }
    }
    return true; // If we arrive at this stage, then the above code by somehow inserted the values
}

void solveSudoku(vector<vector<int>> &sudoku)
{
    solve(sudoku);
}
int main()
{
    vector<vector<char>> sudoku = {
        {'5', '3', '.', '.', '7', '.', '.', '.', '.'},
        {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
        {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
        {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
        {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
        {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
        {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
        {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
        {'.', '.', '.', '.', '8', '.', '.', '7', '9'},

    };

    // solveSudoku(sudoku); This line is right
    return 0;
}