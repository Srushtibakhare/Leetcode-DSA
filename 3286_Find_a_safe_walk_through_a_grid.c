#include <stdio.h>
#include <stdbool.h>

#define MAX 50
#define MAXNODES 2505

typedef struct {
    int row;
    int col;
    int health;
} Node;

// Function Prototype
bool findSafeWalk(int** grid, int gridSize, int* gridColSize, int health);

int main() {

    int row0[] = {0,1,0,0,0};
    int row1[] = {0,1,0,1,0};
    int row2[] = {0,0,0,1,0};

    int *grid[] = {row0, row1, row2};

    int cols = 5;

    if (findSafeWalk(grid, 3, &cols, 1))
        printf("true\n");
    else
        printf("false\n");

    return 0;
}

bool findSafeWalk(int** grid, int gridSize, int* gridColSize, int health) {

    int m = gridSize;
    int n = gridColSize[0];

    int best[MAX][MAX];

    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            best[i][j] = -1;

    Node queue[MAXNODES];
    int front = 0, rear = 0;

    int startHealth = health - grid[0][0];

    if (startHealth <= 0)
        return false;

    queue[rear++] = (Node){0, 0, startHealth};
    best[0][0] = startHealth;

    int dr[4] = {-1, 1, 0, 0};
    int dc[4] = {0, 0, -1, 1};

    while (front < rear) {

        Node curr = queue[front++];

        if (curr.row == m - 1 && curr.col == n - 1)
            return true;

        for (int i = 0; i < 4; i++) {

            int nr = curr.row + dr[i];
            int nc = curr.col + dc[i];

            if (nr < 0 || nr >= m || nc < 0 || nc >= n)
                continue;

            int newHealth = curr.health - grid[nr][nc];

            if (newHealth <= 0)
                continue;

            if (newHealth > best[nr][nc]) {

                best[nr][nc] = newHealth;
                queue[rear++] = (Node){nr, nc, newHealth};
            }
        }
    }

    return false;
}