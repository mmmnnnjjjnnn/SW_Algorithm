n, m = map(int, input().split())
arr = list(map(int, input().split()))

start = 0
end = max(arr)

while start <= end:
    mid = (start + end) // 2
    total = 0
    
    for x in arr:
        if x >= mid:
            total += x - mid
    
    if total > m:
        h = mid
        start = mid + 1
    elif total < m:
        end = mid - 1
    else:
        h = mid
        break

print(h)
