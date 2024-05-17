#include <iostream>
#include <queue>
#include <algorithm>
#define MAX	100

using namespace std;

int COL, ROW, HEI;
int arr[MAX][MAX][MAX];

enum STATE {
	INMATURE,
	MATURE,
};

struct LOCA {
	int h, r, c;
};

queue<LOCA> q;
int visited[MAX][MAX][MAX] = { 0 };
int days;
int inmatureCount;

void input() {
	cin >> COL >> ROW >> HEI;
	
	int item;
	for (int h = 0; h < HEI; h++) {
		for (int r = 0; r < ROW; r++) {
			for (int c = 0; c < COL; c++) {
				cin >> item;

				switch (item)
				{
				case INMATURE:
					inmatureCount++;
					break;
				case MATURE:
					q.push({ h, r, c });
					visited[h][r][c] = 1;
					break;
				}

				arr[h][r][c] = item;
			}
		}
	}
}

const int dr[] = { 0,0,0,0,1,-1 };
const int dc[] = { 0,0,1,-1,0,0 };
const int dh[] = { 1,-1,0,0,0,0 };

void bfs() {

	while (!q.empty()) {
		int r = q.front().r;
		int c = q.front().c;
		int h = q.front().h;
		int v = visited[h][r][c];
		q.pop();

		days = max(days, v - 1);

		for (int d = 0; d < 6; d++) {
			int nr = r + dr[d];
			int nc = c + dc[d];
			int nh = h + dh[d];

			// 1. 맵의 범위 내에 있는지 여부 체크
			if (nr >= ROW || nr < 0 || nc >= COL || nc < 0 || nh >= HEI || nh < 0) continue;

			// 2. inmature인지 체크
			if (arr[nh][nr][nc] != INMATURE) continue;

			// 3. 방문한 노드인지 체크
			if (visited[nh][nr][nc] > 0) continue;

			q.push({ nh,nr,nc });
			visited[nh][nr][nc] = v + 1;
			
			inmatureCount--;
		}
	}
}

void solve() {
	// 저장될 때부터 모든 토마토가 익어있는 상태이면 0을 출력
	if (inmatureCount == 0) {
		cout << 0; 
		return;
	}

	bfs();

	// 토마토가 모두 익지는 못하는 상황이면 -1을 출력
	if (inmatureCount != 0) cout << -1;
	else cout << days;
}

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);

	input();
	solve();
}