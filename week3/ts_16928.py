from collections import deque

n, m = map(int, input().split())
ladder = []
for _ in range(n):
    ladder.append(list(map(int, input().split())))
snake = []
for _ in range(m):
    snake.append(list(map(int, input().split())))

cnt = 0
queue = deque([(1, cnt)])

visited = [False for _ in range(101)]

while queue:
    p, cnt = queue.popleft()
    if p == 100:
        break

    for i in range(1, 7):
        np = p + i

        for k in range(n):
            if np == ladder[k][0]:
                np = ladder[k][1]
                
        for j in range(m):
            if np == snake[j][0]:
                np = snake[j][1]

        if np > 100:
            continue

        if visited[np] is False:
            queue.append((np, cnt + 1))
            visited[np] = True

print(cnt)
