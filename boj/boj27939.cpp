#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	deque<bool> A(N);
	for (int i = 0; i < N; ++i) {
		char c{};
		cin >> c;
		A[i] = c == 'W';
	}
	int M{}, K{};
	cin >> M >> K;
	bool yes{};
	while (M--) {
		bool flag = true;
		for (int i = 0; i < K; ++i) {
			int x{};
			cin >> x;
			flag &= A[x - 1];
		}
		yes |= flag;
	}
	cout << (yes ? "W" : "P") << "\n";
	return 0;
}
