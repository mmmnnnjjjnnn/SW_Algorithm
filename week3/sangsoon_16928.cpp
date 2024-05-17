#include <iostream>
#include <queue>
#include <unordered_map>

using namespace std;

int ladders, snakes;
unordered_map<int, int>shortCut;
int visited[101] = { 0 };

void input() {
	cin >> ladders >> snakes;
	
	int n1, n2;
	for (int i = 0; i < ladders + snakes; i++) {
		cin >> n1 >> n2;
		shortCut[n1] = n2;
	}
}

void solve() {
	visited[1] = 1;
	queue<int> q;
	q.push(1);

	while (!q.empty()) {
		int now = q.front();
		int v = visited[now];
		q.pop();

		if (now == 100) break;
		
		for (int dice = 1; dice <= 6; dice++) {
			int next = now + dice;

			if (next > 100) continue;

			// 사다리나 뱀이 있는 경우
			if (shortCut.count(next) == 1) {
				next = shortCut[next];
			}

			if (visited[next] != 0) continue;
			
			q.push(next);
			visited[next] = v + 1;
		}
	}

	cout << visited[100] - 1;
}

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);

	input();
	solve();
}