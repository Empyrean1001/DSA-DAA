#include <iostream>
#include <ctime>
using namespace std;
#define N 4
bool isSafe(int board[N][N], int row, int col)
{
    int i, j;
    for (i = 0; i < col; i++)
        if (board[row][i])
            return false;

    for (i = row, j = col; i >= 0 && j >= 0; i--, j--)
        if (board[i][j])
            return false;

    for (i = row, j = col; j >= 0 && i < N; i++, j--)
        if (board[i][j])
            return false;

    return true;
}

bool NQueen(int board[N][N], int col)
{
    if (col >= N)
        return true;

    for (int i = 0; i < N; i++)
    {
        if (isSafe(board, i, col))
        {
            board[i][col] = 1;
            if (NQueen(board, col + 1))
                return true;

            board[i][col] = 0;
        }
    }
    return false;
}

int main()
{
    int n; // size of chessboard
    // cin >> n;
    // N = n;

    int board[N][N]; // position of queens in the columns
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            board[i][j] = 0;
        }
    }
    clock_t tstart = clock();
    if (NQueen(board, 0) == false)
    {
        // cout << "Solution doesnt exist";
    }
    else
    {
        // for (int i = 0; i < N; i++)
        // {
        //     for (int j = 0; j < N; j++)
        //     {
        //         if (board[i][j])
        //             cout << j + 1 << "  ";
        //     }
        // }
    }
    double time1 = (double)(clock() - tstart) / CLOCKS_PER_SEC;
    cout << "Time taken by N-Queens Algorithm is: " << time1 << endl;
}