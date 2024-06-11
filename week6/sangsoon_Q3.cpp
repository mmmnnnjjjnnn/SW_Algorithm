#include <iostream>
#include <queue>
#include <algorithm>

#define MAX	4001
#define CTOI(a)	a-'0'

using namespace std;

bool arr[MAX][MAX] = { false };
int N;
string comm;

int r = 2000, c = 2000;
int minr = MAX, minc = MAX, maxr = 0, maxc = 0;

void input() {
	cin >> N;
	cin >> comm;
}

const int dr[] = { 0,0,1,-1 };
const int dc[] = { 1,-1,0,0 };

void searching() {

	arr[r][c] = true;

	int d = 0;				// 방향
	int nr = 0, nc = 0;		// *2 했을 때 다음 좌표
	int mr = 0, mc = 0;		// *1 했을 때 중간 좌표

	for (char com : comm) {

		d = CTOI(com);
		nr = r + dr[d] * 2;
		nc = c + dc[d] * 2;
		
		if (nr >= MAX || nr < 0 || nc >= MAX || nc < 0) {
			continue;
		}

		mr = r + dr[d];
		mc = c + dc[d];
		arr[mr][mc] = true;
		arr[nr][nc] = true;

		r = nr;
		c = nc;

		minr = min(minr, r);
		minc = min(minc, c);
		maxr = max(maxr, r);
		maxc = max(maxc, c);
	}
}

void bfs(int _r, int _c) {
	queue<pair<int, int>> q;
	q.push({ _r,_c });
	arr[_r][_c] = true;

	while (!q.empty()) {
		int r = q.front().first;
		int c = q.front().second;
		q.pop();

		for (int d = 0; d < 4; d++) {
			int nr = r + dr[d];
			int nc = c + dc[d];

			if (nr > maxr || nr < minr || nc >= maxc || nc < minc) {
				continue;
			}

			if (arr[nr][nc]) {
				continue;
			}

			q.push({ nr,nc });
			arr[nr][nc] = true;
		}
	}
}

int getArea() {
	// 1. 테두리 바깥 쪽 bfs
	for (int i = minr; i <= maxr; i++) {
		if (!arr[i][minc]) {
			bfs(i, minc);
		}
		if (!arr[i][maxc]) {
			bfs(i, maxc);
		}
	}
	for (int j = minc; j <= maxc; j++) {
		if (!arr[minr][j]) {
			bfs(minr, j);
		}
		if (!arr[maxr][j]) {
			bfs(maxr, j);
		}
	}

	// 2. 테두리 안 쪽 영역 카운트
	int cnt = 0;
	for (int i = minr + 1; i < maxr; i++) {
		for (int j = minc + 1; j < maxc; j++) {
			if (!arr[i][j]) {
				bfs(i, j);
				cnt++;
			}
		}
	}

	return cnt;
}

void solve() {
	searching();
	int ret = getArea();
	cout << ret;
}

int main() {
	input();
	solve();
}