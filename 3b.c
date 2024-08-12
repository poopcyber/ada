#include <stdio.h>

int a[20][20], reach[20], n;

void bfs(int v) {
    int i, u, f = 0, r = -1, q[20];
    reach[v] = 1;
    q[++r] = v;  // Enqueue the starting vertex

    while (f <= r) {
        u = q[f++];  // Dequeue
        for (i = 0; i < n; i++) {
            if (a[u][i] && !reach[i]) {
                q[++r] = i;  // Enqueue
                reach[i] = 1;
            }
        }
    }
}

int main() {
    int i, j, source;

    printf("Enter the number of vertices:\n");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        reach[i] = 0;
    }

    printf("Enter the adjacency matrix:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &a[i][j]);
        }
    }

    printf("Enter the source vertex:\n");
    scanf("%d", &source);

    bfs(source);

    for (i = 0; i < n; i++) {
        if (reach[i]) {
            printf("%d is reachable\n", i);
        } else {
            printf("%d is not reachable\n", i);
        }
    }

    return 0;
}

