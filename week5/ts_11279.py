import sys
from queue import PriorityQueue
input = sys.stdin.readline

n = int(input())
q = PriorityQueue()

for i in range(n):
    x = int(input())

    if x == 0:
        if q.qsize() == 0:
            print(0)
        else:
            print(-q.get())
    else:
        q.put(-x)
