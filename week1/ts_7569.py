from collections import deque

c, r, h = map(int, input().split())

arr = []  # (층, 행, 열)

for i in range(h):
    temp = []
    for j in range(r):
        temp.append(list(map(int, input().split())))
    arr.append(temp)

queue = deque()
day = 0

for i in range(h):
    for j in range(r):
        for k in range(c):
            if arr[i][j][k] == 1:
                queue.append((i, j, k, day))


dx = [1, -1, 0, 0, 0, 0]
dy = [0, 0, 1, -1, 0, 0]
dz = [0, 0, 0, 0, 1, -1]

while queue:
    v = queue.popleft()
    x, y, z, d = v
    day = d
    for i in range(6):
        nx = x + dx[i]
        ny = y + dy[i]
        nz = z + dz[i]

        if 0 <= nx < h and 0 <= ny < r and 0 <= nz < c:
            if arr[nx][ny][nz] == 0:
                queue.append((nx, ny, nz, d + 1))
                arr[nx][ny][nz] = 1

flag = True
for i in range(h):
    for j in range(r):
        for k in range(c):
            if arr[i][j][k] == 0:
                flag = False
                break

if flag:
    print(day)
else:
    print('-1')
