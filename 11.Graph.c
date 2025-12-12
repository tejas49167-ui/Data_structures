#include <stdio.h>
#include <stdlib.h>

int adj[50][50], visited[50];
int queue[50], front = -1, rear = -1;
int n;

/* ---------- BFS FUNCTION ---------- */
void bfs(int start) {
    int current, i;

    visited[start] = 1;
    queue[++rear] = start;

    printf("%d ", start);

    while (front != rear) {
        current = queue[++front];

        for (i = 1; i <= n; i++) {
            if (adj[current][i] == 1 && visited[i] == 0) {
                visited[i] = 1;
                queue[++rear] = i;
                printf("%d ", i);
            }
        }
    }
}

/* ---------- DFS FUNCTION ---------- */
void dfs(int start) {
    int i;

    visited[start] = 1;
    printf("%d ", start);

    for (i = 1; i <= n; i++) {
        if (adj[start][i] == 1 && visited[i] == 0) {
            dfs(i);
        }
    }
}

/* ---------- MAIN FUNCTION ---------- */
int main() {
    int choice, start, i, j;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix:\n");
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            scanf("%d", &adj[i][j]);
        }
    }

    printf("Enter starting vertex: ");
    scanf("%d", &start);

    printf("\n1. BFS (Print reachable nodes)");
    printf("\n2. DFS (Print reachable nodes)");
    printf("\n3. Exit");
    printf("\nEnter your choice: ");
    scanf("%d", &choice);

    /* Reset visited[] before traversal */
    for (i = 1; i <= n; i++)
        visited[i] = 0;

    switch (choice) {
        case 1:
            printf("\nReachable nodes using BFS starting from %d:\n", start);
            bfs(start);

            /* Print unreachable nodes */
            for (i = 1; i <= n; i++) {
                if (visited[i] == 0)
                    printf("\nNode %d is NOT reachable.", i);
            }
            break;

        case 2:
            printf("\nReachable nodes using DFS starting from %d:\n", start);
            dfs(start);
            break;

        case 3:
            exit(0);

        default:
            printf("Invalid choice\n");
    }

    return 0;
}

