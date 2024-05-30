#include <iostream>
#include <vector>
#define MAX_LEN	100
#define SIDE_LEN	10

using namespace std;

int N;
vector<pair<int, int>> v;
bool map[MAX_LEN][MAX_LEN] = { false };

void input() {
	cin >> N;

	int x, y;
	for (int i = 0; i < N; i++) {
		cin >> x >> y;
		v.push_back({ x,y });
	}
}

int getCoveredArea(int sx, int sy) {

	int cnt = 0;
	for (int y = sy; y < sy + SIDE_LEN; y++) {
		for (int x = sx; x < sx + SIDE_LEN; x++) {
			if (!map[x][y]) {
				map[x][y] = true;
				cnt++;
			}
		}
	}

	return cnt;
}

void solve() {
	int x, y;
	int totalArea = 0;

	for (pair<int, int>p : v) {
		x = p.first;
		y = p.second;

		totalArea += getCoveredArea(x, y);
	}

	cout << totalArea;
}

int main() {
	input();
	solve();
}