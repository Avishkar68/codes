#include <stdio.h>
#include <string.h>
#include <time.h>

int main()
{
    char text[100], pattern[100];
    int i, n, m;
    int textHash, patternHash;
    int q = 11;

    clock_t start, end;

    printf("Enter text: ");
    scanf("%s", text);

    printf("Enter pattern: ");
    scanf("%s", pattern);

    n = strlen(text);
    m = strlen(pattern);

    // Convert pattern to integer
    int p = atoi(pattern);

    patternHash = p % q;

    start = clock();

    for(i = 0; i <= n - m; i++)
    {
        char temp[10];

        strncpy(temp, text + i, m);
        temp[m] = '\0';

        int num = atoi(temp);

        textHash = num % q;

        // Hash matched
        if(textHash == patternHash)
        {
            // Exact match check
            if(strcmp(temp, pattern) == 0)
            {
                printf("Pattern found at position %d\n",
                       i + 1);
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