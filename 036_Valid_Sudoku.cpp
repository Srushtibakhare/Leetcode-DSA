#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

bool isValidSudoku(vector<vector<char>>& board)
{
    unordered_set<string> seen;

    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            if (board[i][j] == '.')
                continue;

            string row = "R" + to_string(i) + board[i][j];
            string col = "C" + to_string(j) + board[i][j];
            string box = "B" + to_string((i / 3) * 3 + (j / 3)) + board[i][j];

            if (seen.count(row) || seen.count(col) || seen.count(box))
                return false;

            seen.insert(row);
            seen.insert(col);
            seen.insert(box);
        }
    }

    return true;
}

int main()
{
    vector<vector<char>> board = {
        {'5','3','.','.','7','.','.','.','.'},
        {'6','.','.','1','9','5','.','.','.'},
        {'.','9','8','.','.','.','.','6','.'},
        {'8','.','.','.','6','.','.','.','3'},
        {'4','.','.','8','.','3','.','.','1'},
        {'7','.','.','.','2','.','.','.','6'},
        {'.','6','.','.','.','.','2','8','.'},
        {'.','.','.','4','1','9','.','.','5'},
        {'.','.','.','.','8','.','.','7','9'}
    };

    if (isValidSudoku(board))
        cout << "Valid Sudoku";
    else
        cout << "Invalid Sudoku";

    return 0;
}