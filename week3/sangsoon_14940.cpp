#include <iostream>
#include <queue>
#define MAX	1000

using namespace std;

int ROW, COL;
int arr[MAX][MAX];
int visited[MAX][MAX];

pair<int, int> starter;

void input() {
	cin >> ROW >> COL;

	int n;
	for (int i = 0; i < ROW; i++) {
		for (int j = 0; j < COL; j++) {
			cin >> n;
			arr[i][j] = n;

			if (n == 2) {
				starter = { i, j };
			}
		}
	}
}

int dr[] = { 1,-1,0,0 };
int dc[] = { 0,0,1,-1 };

void solve() {
	queue<pair<int, int>> q;
	q.push(starter);

	while (!q.empty()) {
		int r = q.front().first;
		int c = q.front().second;
		int v = visited[r][c];
		q.pop();

		for (int d = 0; d < 4; d++) {
			int nr = r + dr[d];
			int nc = c + dc[d];

			/*
				1. 범위 벗어나면 컨티뉴
				2. 갈 수 없는 땅이면 컨티뉴
				3. 이미 방문한 땅이면 컨티뉴
			*/

			if (nr < 0 || nr >= ROW || nc < 0 || nc >= COL) continue;
			if (arr[nr][nc] != 1) continue;
			if (visited[nr][nc] != 0) continue;

			q.push({ nr,nc });
			visited[nr][nc] = v + 1;
		}
	}

	// 원래 갈 수 있는 땅인데 도달하지 못한다면 -1 
	for (int i = 0; i < ROW; i++) {
		for (int j = 0; j < COL; j++) {
			if (arr[i][j] == 1 && visited[i][j] == 0)
				visited[i][j] = -1;

			cout << visited[i][j] << " ";
		}
		cout << "\n";
	}
}

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);

	input();
	solve();
}