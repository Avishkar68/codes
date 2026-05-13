#include <stdio.h>
#include <time.h>

#define INF 999

int main()
{
    int n, i, j, source;
    int cost[10][10], dist[10], visited[10];
    int min, nextNode;

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

    // Initialize
    for(i = 0; i < n; i++)
    {
        dist[i] = cost[source][i];
        visited[i] = 0;
    }

    dist[source] = 0;
    visited[source] = 1;

    // Dijkstra Logic
    for(i = 1; i < n; i++)
    {
        min = INF;

        for(j = 0; j < n; j++)
        {
            if(dist[j] < min && !visited[j])
            {
                min = dist[j];
                nextNode = j;
            }
        }

        visited[nextNode] = 1;

        for(j = 0; j < n; j++)
        {
            if(!visited[j] &&
               min + cost[nextNode][j] < dist[j])
            {
                dist[j] = min + cost[nextNode][j];
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