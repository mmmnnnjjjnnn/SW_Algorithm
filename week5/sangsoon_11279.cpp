#include <iostream>
#include <queue>

using namespace std;

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);

	int N;
	cin >> N;

	int comm;
	priority_queue<int>pq;
	while (N--) {
		cin >> comm;

		if (comm == 0) {
			if (pq.empty()) {
				cout << "0\n";
			}
			else {
				cout << pq.top() << "\n";
				pq.pop();
			}
		}
		else {
			pq.push(comm);
		}
	}
}