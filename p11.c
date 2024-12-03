#include <stdio.h>
#include <stdlib.h>

#define MAX_CITIES 20  // Maximum number of cities (nodes)

// Graph structure
int graph[MAX_CITIES][MAX_CITIES];  // Adjacency matrix
int visited[MAX_CITIES];  // To track visited nodes for DFS/BFS

// Function to create the graph
void createGraph(int n) {
    int i, j;
    // Initialize the adjacency matrix with 0s
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            graph[i][j] = 0;
        }
    }

    printf("Enter the edges (from to). Enter -1 -1 to stop.\n");
    while (1) {
        int u, v;
        printf("Enter edge (from city, to city): ");
        scanf("%d %d", &u, &v);
        if (u == -1 && v == -1) break;  // Terminate input on -1 -1
        
        if (u >= 0 && u < n && v >= 0 && v < n) {
            graph[u][v] = 1;  // Directed edge from u to v
        } else {
            printf("Invalid cities. Please enter values between 0 and %d.\n", n-1);
        }
    }
}

// DFS function to explore reachable nodes
void dfs(int start, int n) {
    visited[start] = 1;
    printf("City %d ", start);  // Printing the city number
    
    for (int i = 0; i < n; i++) {
        if (graph[start][i] == 1 && !visited[i]) {
            dfs(i, n);
        }
    }
}

// BFS function to explore reachable nodes
void bfs(int start, int n) {
    int queue[MAX_CITIES];
    int front = 0, rear = 0;

    visited[start] = 1;
    queue[rear++] = start;  // Add the start city to the queue

    while (front < rear) {
        int city = queue[front++];
        printf("City %d ", city);  // Printing the city number
        
        // Explore neighbors
        for (int i = 0; i < n; i++) {
            if (graph[city][i] == 1 && !visited[i]) {
                visited[i] = 1;
                queue[rear++] = i;
            }
        }
    }
}

// Main driver function
int main() {
    int n, start, choice;

    // Input number of cities (nodes)
    printf("Enter the number of cities: ");
    scanf("%d", &n);

    // Initialize visited array
    for (int i = 0; i < n; i++) {
        visited[i] = 0;
    }

    // Create graph
    createGraph(n);

    // Menu for operations
    while (1) {
        printf("\nGraph Operations:\n");
        printf("1. DFS from a starting city\n");
        printf("2. BFS from a starting city\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                // DFS operation
                printf("Enter the starting city for DFS (0 to %d): ", n - 1);
                scanf("%d", &start);
                if (start < 0 || start >= n) {
                    printf("Invalid city.\n");
                    break;
                }

                // Reset visited array for DFS
                for (int i = 0; i < n; i++) {
                    visited[i] = 0;
                }

                printf("Cities reachable from city %d using DFS: ", start);
                dfs(start, n);
                printf("\n");
                break;

            case 2:
                // BFS operation
                printf("Enter the starting city for BFS (0 to %d): ", n - 1);
                scanf("%d", &start);
                if (start < 0 || start >= n) {
                    printf("Invalid city.\n");
                    break;
                }

                // Reset visited array for BFS
                for (int i = 0; i < n; i++) {
                    visited[i] = 0;
                }

                printf("Cities reachable from city %d using BFS: ", start);
                bfs(start, n);
                printf("\n");
                break;

            case 3:
                printf("Exiting...\n");
                return 0;

            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
