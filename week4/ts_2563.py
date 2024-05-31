n = int(input())
arr = []
for _ in range(n):
    arr.append(map(int, input().split()))

visited = []
for _ in range(101):
    visited.append([False for _ in range(101)])

cnt = 0

for i in range(n):
    x, y = arr[i]
    for a in range(10):
        for b in range(10):
            if visited[x + a][y + b] is False:
                visited[x + a][y + b] = True
                cnt += 1

print(cnt)
