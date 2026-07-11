#include <stdio.h>
#include <stdlib.h>

#define MAX 55

int graph[MAX][MAX];
int degree[MAX];
int visited[MAX];

int nodeCount;
int edgeCount;

void dfs(int node)
{
    visited[node] = 1;

    nodeCount++;

    edgeCount += degree[node];

    for(int i = 0; i < degree[node]; i++)
    {
        int neighbour = graph[node][i];

        if(!visited[neighbour])
        {
            dfs(neighbour);
        }
    }
}

int countCompleteComponents(int n, int edges[][2], int edgesSize)
{
    for(int i = 0; i < MAX; i++)
    {
        degree[i] = 0;
        visited[i] = 0;
    }

    // Build Graph

    for(int i = 0; i < edgesSize; i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];

        graph[u][degree[u]++] = v;
        graph[v][degree[v]++] = u;
    }

    int answer = 0;

    for(int i = 0; i < n; i++)
    {
        if(!visited[i])
        {
            nodeCount = 0;
            edgeCount = 0;

            dfs(i);

            edgeCount /= 2;

            if(edgeCount == nodeCount * (nodeCount - 1) / 2)
            {
                answer++;
            }
        }
    }

    return answer;
}

int main()
{
    int edges[][2] = {
        {0,1},
        {0,2},
        {1,2},
        {3,4}
    };

    int n = 6;

    int ans = countCompleteComponents(n, edges, 4);

    printf("Complete Components = %d\n", ans);

    return 0;
}