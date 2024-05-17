#include <iostream>
#include <vector>
#include <queue>
#define MAX	1000001

using namespace std;

int visited[MAX];
queue<int> q;
int N;

void solve() {
	q.push(N);

	while (!q.empty()) {
		int now = q.front();
		int v = visited[now];
		q.pop();

		if (now == 1) break;

		if (now % 3 == 0 && !visited[now / 3]) {
			q.push(now / 3);
			visited[now / 3] = v + 1;
		}
		if (now % 2 == 0 && !visited[now / 2]) {
			q.push(now / 2);
			visited[now / 2] = v + 1;
		}
		if (!visited[now - 1]) {
			q.push(now - 1);
			visited[now - 1] = v + 1;
		}
	}

	cout << visited[1];
}

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);

	cin >> N;
	solve();
}