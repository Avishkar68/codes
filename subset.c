#include <stdio.h>
#include <time.h>

int set[20], subset[20];
int n, target;

void sumOfSubsets(int sum, int k, int index)
{
    int i;

    // Target found
    if(sum == target)
    {
        printf("Subset: ");

        for(i = 0; i < k; i++)
        {
            printf("%d ", subset[i]);
        }

        printf("\n");
        return;
    }

    // Try remaining elements
    for(i = index; i < n; i++)
    {
        if(sum + set[i] <= target)
        {
            subset[k] = set[i];

            sumOfSubsets(sum + set[i],
                         k + 1,
                         i + 1);
        }
    }
}

int main()
{
    int i;

    clock_t start, end;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter elements:\n");

    for(i = 0; i < n; i++)
    {
        scanf("%d", &set[i]);
    }

    printf("Enter target sum: ");
    scanf("%d", &target);

    start = clock();

    printf("\nPossible Subsets:\n");

    sumOfSubsets(0, 0, 0);

    end = clock();

    double time_taken =
    ((double)(end - start)) / CLOCKS_PER_SEC;

    printf("\nRunning Time = %f seconds\n",
           time_taken);

    return 0;
}