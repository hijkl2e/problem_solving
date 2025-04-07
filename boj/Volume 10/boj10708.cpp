#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, M{};
	cin >> N >> M;
	vector<int> A(M);
	for (int i = 0; i < M; ++i) {
		cin >> A[i];
	}
	vector<int> B(N + 1);
	for (int i = 0; i < M; ++i) {
		int cnt{};
		for (int j = 1; j <= N; ++j) {
			int x{};
			cin >> x;
			if (x == A[i]) {
				++B[j];
			} else {
				++cnt;
			}
		}
		B[A[i]] += cnt;
	}
	for (int i = 1; i <= N; ++i) {
		cout << B[i] << "\n";
	}
	return 0;
}
