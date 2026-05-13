#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int board[10];
int n;

int safe(int row, int col)
{
    int i;

    for(i = 0; i < row; i++)
    {
        // Same column
        if(board[i] == col)
            return 0;

        // Same diagonal
        if(abs(board[i] - col) ==
           abs(i - row))
            return 0;
    }

    return 1;
}

int solve(int row)
{
    int col;

    // All queens placed
    if(row == n)
        return 1;

    for(col = 0; col < n; col++)
    {
        if(safe(row, col))
        {
            board[row] = col;

            if(solve(row + 1))
                return 1;
        }
    }

    return 0;
}

int main()
{
    int i, j;

    clock_t start, end;

    printf("Enter number of queens: ");
    scanf("%d", &n);

    start = clock();

    if(solve(0))
    {
        printf("\nSolution:\n");

        for(i = 0; i < n; i++)
        {
            for(j = 0; j < n; j++)
            {
                if(board[i] == j)
                    printf("Q ");
                else
                    printf(". ");
            }

            printf("\n");
        }
    }
    else
    {
        printf("No Solution Found");
    }

    end = clock();

    double time_taken =
    ((double)(end - start)) / CLOCKS_PER_SEC;

    printf("\nRunning Time = %f seconds\n",
           time_taken);

    return 0;
}