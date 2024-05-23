from collections import deque

n = int(input())
cnt = 0

queue = deque([(n, cnt)])
visited = [False for _ in range(10 ** 6 + 1)]

while queue:
    q = queue.popleft()
    x, cnt = q

    if x == 1:
        break

    if x % 3 == 0 and visited[x // 3] is False:
        queue.append((x // 3, cnt + 1))
        visited[x // 3] = True
    if x % 2 == 0 and visited[x // 2] is False:
        queue.append((x // 2, cnt + 1))
        visited[x // 2] = True
    if x - 1 >= 0 and visited[x - 1] is False:
        queue.append((x - 1, cnt + 1))
        visited[x - 1] = True

print(cnt)
