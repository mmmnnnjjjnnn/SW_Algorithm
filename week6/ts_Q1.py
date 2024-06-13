##### 수정 불가(Input data)
R, C = map(int, input().split())
Mat = [list(map(int, input().split())) for _ in range(R)]
 
 
 
##### 수정 가능(Rotate 함수, 시계 방향 회전으로 주어짐)
def Rotate(sr, sc, er, ec):
    if sr < er and sc < ec:    
        a = Mat[sr][sc]
  
        for r in range(sr + 1, er + 1):
            Mat[r][sc], a = a, Mat[r][sc]
 
        for c in range(sc + 1, ec + 1):
            Mat[er][c], a = a, Mat[er][c]

        for r in range(er - 1, sr - 1, -1):
            Mat[r][ec], a = a, Mat[r][ec]   

        for c in range(ec - 1, sc - 1, -1):
            Mat[sr][c], a = a, Mat[sr][c]


##### 수정 불가(Rotate 함수 호출 및 결과 출력)
N = max(R, C)
for i in range(N):
    Rotate(i, i, R-i-1, C-i-1)
 
for i in range(R):
    print(*Mat[i])
 
 
 
'''
Input Sample
3 3
1 2 3
4 5 6
7 8 9
 
Expected Output
2 3 6
1 5 9
4 7 8
 
주의) R != C인 케이스도 통과해야 함.
Input Sample
5 7
1 2 3 4 5 6 7
8 9 10 11 12 13 14
15 16 17 18 19 20 21
22 23 24 25 26 27 28
29 30 31 32 33 34 35

Expected Output (1)
8 1 2 3 4 5 6 
15 16 9 10 11 12 7
22 23 17 18 19 13 14
29 24 25 26 27 20 21
30 31 32 33 34 35 28

Expected Output (2)
2 3 4 5 6 7 14
1 10 11 12 13 20 21
8 9 17 18 19 27 28
15 16 23 24 25 26 25
22 29 30 31 32 33 34

Input Sample
7 5
1 2 3 4 5
6 7 8 9 10
11 12 13 14 15
16 17 18 19 20
21 22 23 24 25
26 27 28 29 30
31 32 33 34 35
'''