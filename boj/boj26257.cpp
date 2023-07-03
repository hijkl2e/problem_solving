#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, M{}, Q{};
	cin >> N >> M >> Q;
	vector<int> A(M + 1);
	for (int i = 1; i <= M; ++i) {
		cin >> A[i];
	}
	while (Q--) {
		string cmd;
		int x{}, y{};
		cin >> cmd >> x;
		if (cmd == "reset") {
			A[x] = 0;
			continue;
		}
		cin >> y;
		if (cmd == "assign") {
			A[x] = A[y];
		} else {
			swap(A[x], A[y]);
		}
	}
	deque<bool> B(N + 1);
	for (int i = 1; i <= M; ++i) {
		B[A[i]] = true;
	}
	int cnt = count(B.begin() + 1, B.end(), true);
	cout << cnt << "\n";
	for (int i = 1; i <= N; ++i) {
		if (B[i]) {
			cout << i << "\n";
		}
	}
	return 0;
}
