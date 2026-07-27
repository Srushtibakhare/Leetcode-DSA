from collections import defaultdict

def minScore(n, roads):

    graph = defaultdict(list)

    # Build Graph
    for u, v, d in roads:
        graph[u].append((v, d))
        graph[v].append((u, d))

    visited = [False] * (n + 1)

    answer = float('inf')

    def dfs(city):
        nonlocal answer

        visited[city] = True

        for neighbor, distance in graph[city]:

            answer = min(answer, distance)

            if not visited[neighbor]:
                dfs(neighbor)

    dfs(1)

    return answer


def main():

    n = 4

    roads = [
        [1, 2, 9],
        [2, 3, 6],
        [2, 4, 5],
        [1, 4, 7]
    ]

    print("Minimum Score =", minScore(n, roads))


if __name__ == "__main__":
    main()