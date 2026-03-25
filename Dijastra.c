#include <stdio.h>

void dijkstras(int n, int cost[10][10], int s, int dist[10]) {
    int visited[10], count, min, nextnode, i, j;

    // Initialization
    for (i = 1; i <= n; i++) {
        visited[i] = 0;
        dist[i] = cost[s][i];
    }

    dist[s] = 0;
    visited[s] = 1;
    count = 1;

    while (count < n) {
        min = 999;

        // Find the next node with minimum distance
        for (i = 1; i <= n; i++) {
            if (dist[i] < min && !visited[i]) {
                min = dist[i];
                nextnode = i;
            }
        }

        visited[nextnode] = 1;

        // Update distances
        for (i = 1; i <= n; i++) {
            if (!visited[i]) {
                if (min + cost[nextnode][i] < dist[i]) {
                    dist[i] = min + cost[nextnode][i];
                }
            }
        }

        count++;
    }
}

int main() {
    int cost[10][10], dist[10];
    int n, i, j, s;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    printf("Enter the cost matrix:\n");
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            scanf("%d", &cost[i][j]);

            if (cost[i][j] == 0 && i != j)
                cost[i][j] = 999;  // infinity
        }
    }

    printf("Enter source vertex: ");
    scanf("%d", &s);

    dijkstras(n, cost, s, dist);

    printf("\nShortest distances from source %d:\n", s);
    for (i = 1; i <= n; i++) {
        if (i != s)
            printf("%d -> %d = %d\n", s, i, dist[i]);
    }

    return 0;
}