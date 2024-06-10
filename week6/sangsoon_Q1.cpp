#include <iostream>
#include <algorithm>
#define MAX	100

using namespace std;

int R, C;
int arr[MAX][MAX];
int	arr_rotate[MAX][MAX];

const int dr[] = { 1,0,-1,0 };
const int dc[] = { 0,1,0,-1 };

void input() {
	cin >> R >> C;
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			cin >> arr[i][j];
		}
	}
}

void Rotate() {
	// arr값 arr_rotate에 카피
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			arr_rotate[i][j] = arr[i][j];
		}
	}

	int rcount = min(R, C) / 2;	// 회전할 바깥 껍질의 개수
	for (int i = 0; i < rcount; i++) {
		
		int r = i, c = i;	// (0,0), (1,1), (2,2)... 에서 시작
		for (int d = 0; d < 4; d++) {	// 아래, 오른쪽, 위, 왼쪽 방향

			while (true) {
				int nr = r + dr[d];
				int nc = c + dc[d];

				if (nr >= R - i || nr < i || nc >= C - i || nc < i) {
					break;	// 범위를 벗어나는 경우 방향 바꿈
				}

				arr_rotate[nr][nc] = arr[r][c];
				r = nr;
				c = nc;
			}
		}
	}
}

void print() {
	cout << "result:\n";
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			cout << arr_rotate[i][j] << " ";
		}
		cout << "\n";
	}
}

int main() {
	input();
	Rotate();
	print();
}