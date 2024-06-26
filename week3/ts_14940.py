from collections import deque

n, m = map(int, input().split())
graph = []
for _ in range(n):
    graph.append(list(map(int, input().split())))

dx = [0, 0, 1, -1]
dy = [1, -1, 0, 0]

r, c = 0, 0
for i in range(n):
    for j in range(m):
        if graph[i][j] == 2:
            r, c = i, j
            graph[r][c] = 0

queue = deque([(r, c)])

visited = []
for _ in range(n):
    visited.append([False for _ in range(m)])

while queue:
    x, y = queue.popleft()
    for i in range(4):
        nx = x + dx[i]
        ny = y + dy[i]

        if nx < 0 or nx >= n or ny < 0 or ny >= m:
            continue

        if graph[nx][ny] == 1 and visited[nx][ny] is False:
            graph[nx][ny] = graph[x][y] + 1
            queue.append((nx, ny))
            visited[nx][ny] = True

for i in range(n):
    for j in range(m):
        if graph[i][j] == 1 and visited[i][j] is False:
            graph[i][j] = -1
        print(graph[i][j], end=' ')
    print()
