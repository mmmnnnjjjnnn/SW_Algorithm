n = int(input())
arr = []
for i in range(n):
    arr.append(list(map(int, input().split())))
arr = sorted(arr, key=lambda x: (x[1], x[0]))

cur_s = 0
cur_e = 0
cnt = 0

for i in range(len(arr)):
    s, e = arr[i]
    if s >= cur_e:
        cur_s, cur_e = s, e
        cnt += 1

print(cnt)
