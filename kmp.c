#include <stdio.h>
#include <string.h>
#include <time.h>

void computeLPS(char pat[], int m, int lps[])
{
    int len = 0;
    int i = 1;

    lps[0] = 0;

    while(i < m)
    {
        if(pat[i] == pat[len])
        {
            len++;
            lps[i] = len;
            i++;
        }
        else
        {
            if(len != 0)
            {
                len = lps[len - 1];
            }
            else
            {
                lps[i] = 0;
                i++;
            }
        }
    }
}

int main()
{
    char text[100], pattern[100];

    int n, m;
    int i = 0, j = 0;

    int lps[100];

    clock_t start, end;

    printf("Enter text: ");
    scanf("%s", text);

    printf("Enter pattern: ");
    scanf("%s", pattern);

    n = strlen(text);
    m = strlen(pattern);

    computeLPS(pattern, m, lps);

    start = clock();

    while(i < n)
    {
        if(pattern[j] == text[i])
        {
            i++;
            j++;
        }

        if(j == m)
        {
            printf("Pattern found at position %d\n",
                   i - j + 1);

            j = lps[j - 1];
        }
        else if(i < n && pattern[j] != text[i])
        {
            if(j != 0)
            {
                j = lps[j - 1];
            }
            else
            {
                i++;
            }
        }
    }

    end = clock();

    double time_taken =
    ((double)(end - start)) / CLOCKS_PER_SEC;

    printf("\nRunning Time = %f seconds\n",
           time_taken);

    return 0;
}