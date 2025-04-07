#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9 + 7;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int M{}, N{};
	cin >> M >> N;
	vector<int> A(N);
	for (int i = 0; i < N; ++i) {
		cin >> A[i];
	}
	vector<int> B(400001, INF);
	bool yes{};
	for (int j = 0; j < N; ++j) {
		for (int i = 0; i < j; ++i) {
			int x = A[i] + A[j];
			if (B[x] == INF) {
				B[x] = j;
			}
			x = M - A[i] - A[j];
			if (0 < x && x < B.size() && B[x] < i) {
				yes = true;
			}
		}
	}
	cout << (yes ? "YES" : "NO") << "\n";
	return 0;
}
