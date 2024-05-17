#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M;
vector<int> trees;
int maxLen;
int answer;

void input() {
	cin >> N >> M;

	int n;
	for (int i = 0; i < N; i++) {
		cin >> n;
		trees.push_back(n);
	}
	maxLen = *max_element(trees.begin(), trees.end());
}

long long getTreeRemains(int cuttingLen) {
	long long rem = 0;
	for (int t : trees) {	// 모든 나무들에 대해서 cuttingLen으로 잘랐을 때 남은 길이 계산
		rem += (t > cuttingLen) ? (t - cuttingLen) : 0;
	}
	return rem;
}

void searching(int start, int end) {
	if (start > end) return;

	int mid = (start + end) / 2;	// 나무를 자르는 기준 길이

	long long remains = getTreeRemains(mid);
\
	if (remains >= M) {	// 남은 길이가 M이상인 경우 -> 자르는 길이를 더 높여야 함
		answer = max(answer, mid);
		searching(mid + 1, end);
	}
	else{				// 남은 길이가 M미만인 경우 -> 자르는 길이를 더 낮춰야 함
		searching(start, mid - 1);
	}
}

void solve() {
	searching(1, maxLen - 1);
	cout << answer;
}

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);

	input();
	solve();
}