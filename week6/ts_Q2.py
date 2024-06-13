import sys
 
def InputData():
    readl = sys.stdin.readline
    N, M = map(int,readl().split())
    ID = list(map(int,readl().split()))
    return N, M, ID


def sliding_window(arr, window_size):
    slide = []
    for i in range(len(arr) - window_size + 1):
        slide.append(arr[i:i+window_size])
    return slide
 
ans = -1
# 입력 함수
N, M, ID = InputData()
 
# 여기서부터 작성
slide = sliding_window(ID, M)
cnt = 0

for sl in slide:
    for k in range(min(ID), max(ID) + 1):
        for i in range(M):
            if k-1 <= sl[i] <= k+1:
                cnt += 1
        ans = max(ans, cnt)
        cnt = 0

#     print(sl, end=' -> ')
# print('end')

 
# 출력하는 부분
print(ans)
 
 
'''
Input Sample
10 8
5 3 3 6 10 11 4 4 3 5
 
Expected Output
5
'''