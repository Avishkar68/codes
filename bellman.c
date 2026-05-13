#include <stdio.h>
#include <time.h>

#define INF 999

int main()
{
    int n, i, j, k, source;
    int cost[10][10], dist[10];

    clock_t start, end;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter cost matrix:\n");

    for(i = 0; i < n; i++)
    {
        for(j = 0; j < n; j++)
        {
            scanf("%d", &cost[i][j]);

            if(cost[i][j] == 0)
                cost[i][j] = INF;
        }
    }

    printf("Enter source vertex: ");
    scanf("%d", &source);

    start = clock();

    // Initialize distances
    for(i = 0; i < n; i++)
        dist[i] = INF;

    dist[source] = 0;

    // Bellman Ford Logic
    for(i = 1; i < n; i++)
    {
        for(j = 0; j < n; j++)
        {
            for(k = 0; k < n; k++)
            {
                if(cost[j][k] != INF && dist[j] + cost[j][k] < dist[k])
                {
                    dist[k] = dist[j] + cost[j][k];
                }
            }
        }
    }

    end = clock();

    printf("\nShortest Distances:\n");

    for(i = 0; i < n; i++)
    {
        printf("%d -> %d = %d\n",
               source, i, dist[i]);
    }

    double time_taken =
    ((double)(end - start)) / CLOCKS_PER_SEC;

    printf("\nRunning Time = %f seconds\n",
           time_taken);

    return 0;
}