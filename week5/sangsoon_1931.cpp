#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct CONF {
	int s, e;
};

bool compare(CONF& c1, CONF& c2) {
	if (c1.e != c2.e) {
		return c1.e < c2.e;
	}
	return c1.s < c2.s;
}

int N;
vector<CONF> v;

void input() {
	cin >> N;

	int s, e;
	while (N--) {
		cin >> s >> e;
		v.push_back({ s,e });
	}
}

void solve() {
	int cur = 0, confCount = 0;

	sort(v.begin(), v.end(), compare);
	for (CONF c : v) {
		if (c.s >= cur) {
			cur = c.e;
			confCount++;
		}
	}

	cout << confCount;
}

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);

	input();
	solve();
}