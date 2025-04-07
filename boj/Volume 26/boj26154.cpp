#include <bits/stdc++.h>

using namespace std;

using ii = pair<int, int>;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, M{};
	cin >> N >> M;
	if (M > N) {
		M = N + M % N;
	}
	vector<int> A(2 * N + 1);
	for (int i = 0; i < N; ++i) {
		int p1{}, p2{};
		cin >> p1 >> p2;
		A[p1] = A[p2] = i;
	}
	deque<bool> B(N + 1);
	for (int i = 0; i < M; ++i) {
		fill(B.begin(), B.end(), false);
		for (int j = 1; j <= 2 * N; ++j) {
			auto &x = A[j];
			if (B[x]) {
				x = x ? x - 1 : x;
			} else {
				B[x] = true;
				x = x ? x : (N - 1);
			}
		}
	}
	vector<ii> C(N, {-1, -1});
	for (int i = 1; i <= 2 * N; ++i) {
		auto &p = C[A[i]];
		if (p.first == -1) {
			p.first = i;
		} else {
			p.second = i;
		}
	}
	for (auto &p : C) {
		cout << p.first << " " << p.second << "\n";
	}
	return 0;
}
