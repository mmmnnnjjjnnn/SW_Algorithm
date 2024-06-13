
import sys
 
def InputData():
    readl = sys.stdin.readline
    N = int(readl())
    info = input()
    return N, info
 
sol = 0
 
# 입력
# N: 이동 정보의 개수
# info: 이동 방향 정보
N, info = InputData()
 
# 코드 작성
from collections import deque

info = list(map(int, list(info)))

graph = [[0 for _ in range(2 * N)] for _ in range(2 * N)]
x, y = N, N

dx = [0, 0, 1, -1]
dy = [1, -1, 0, 0]

graph[x][y] = 1
for i in info:
    nx = x + dx[i]
    ny = y + dy[i]

    graph[nx][ny] = 1

    nx = x + dx[i] * 2
    ny = y + dy[i] * 2

    graph[nx][ny] = 1
    
    x = nx
    y = ny


def bfs(x, y):
    queue = deque()
    queue.append((x, y))
    graph[x][y] = 1

    while queue:
        x, y = queue.popleft()

        for i in range(4):
            nx = x + dx[i]
            ny = y + dy[i]

            if nx < 0 or nx >= 2 * N or ny < 0 or ny >= 2 * N:
                continue

            if graph[nx][ny] == 0:
                queue.append((nx, ny))
                graph[nx][ny] = 1


bfs(0, 0)

for i in range(2 * N):
    for j in range(2 * N):
        if graph[i][j] == 0:
            bfs(i, j)
            sol += 1        
             
# 출력
print(sol)
 
 
'''
Input Sample
15
333021112200000
 
Expected Output
2
'''