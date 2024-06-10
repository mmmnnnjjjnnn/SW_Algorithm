#include <iostream>
#include <algorithm>
#define MAX	200000

using namespace std;

int N, M, arr[MAX];

void input() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}
}

bool matched(int val, int k) {
	if (val >= k - 1 && val <= k + 1) {
		return true;
	}
	return false;
}

int solve(int k) {
	int maxCnt = 0;
	
	// 1. init
	int s = 0, e = s + M;

	int cnt = 0;
	for (int i = s; i < e; i++) {
		int cur = arr[i];

		if (matched(cur, k)) {
			cnt++;
		}
	}
	maxCnt = cnt;

	// 2. sliding
	while (e < N) {
		if (matched(arr[s], k)) {
			cnt--;
		}

		if (matched(arr[e], k)) {
			cnt++;
		}

		s++;
		e++;
		maxCnt = max(maxCnt, cnt);
	}

	return maxCnt;
}

int main() {
	input();

	int maxk = 0;
	for (int k = 1; k <= 14; k++) {
		int ret = solve(k);
		maxk = max(maxk, ret);
	}

	cout << maxk;
}