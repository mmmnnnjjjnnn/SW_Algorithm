
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

    if graph[nx][ny] != 0:
        sol += 1
    graph[nx][ny] = graph[x][y] + 1
    
    x = nx
    y = ny
             
# 출력
print(sol)
 
 
'''
Input Sample
15
333021112200000
 
Expected Output
2
'''