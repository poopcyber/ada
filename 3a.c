#include <stdio.h>

int a[20][20], reach[20], n;

void dfs(int v) {
    reach[v] = 1;
    for (int i = 0; i < n; i++) {
        if (a[v][i] && !reach[i]) {
            printf("\n%d --> %d\n", v, i);
            dfs(i);
        }
    }
}

int main() {
    int i, j, source, count = 0;

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

    dfs(source);

    for (i = 0; i < n; i++) {
        if (reach[i]) {
            count++;
        }
    }

    if (count == n) {
        printf("The graph is connected.\n");
    } else {
        printf("The graph is not connected.\n");
    }

    return 0;
}

