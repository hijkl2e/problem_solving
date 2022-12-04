#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	vector<int> A(N);
	for (int i = 0; i < N; ++i) {
		cin >> A[i];
	}
	int M{};
	cin >> M;
	vector<int> B(M);
	for (int i = 0; i < M; ++i) {
		cin >> B[i];
	}
	int minv = 1e9;
	for (int i = 0; i < N; ++i) {
		int K{};
		cin >> K;
		while (K--) {
			int x{};
			cin >> x;
			minv = min(minv, A[i] + B[x - 1]);
		}
	}
	int X{};
	cin >> X;
	int ans = max(X / minv - 1, 0);
	cout << ans << "\n";
	return 0;
}
