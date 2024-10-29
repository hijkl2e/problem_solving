#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9 + 7;

vector<int> X, Y;

int dist(int i, int j) {
	return abs(X[i] - X[j]) + abs(Y[i] - Y[j]);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, K{};
	cin >> N >> K;
	X.resize(N);
	Y.resize(N);
	for (int i = 0; i < N; ++i) {
		cin >> X[i] >> Y[i];
	}
	vector<int> A(N);
	fill(A.begin() + N - K, A.end(), 1);
	int ans = INF;
	do {
		int maxv{};
		for (int i = 0; i < N; ++i) {
			int minv = INF;
			for (int j = 0; j < N; ++j) {
				if (A[j]) {
					minv = min(minv, dist(i, j));
				}
			}
			maxv = max(maxv, minv);
		}
		ans = min(ans, maxv);
	} while (next_permutation(A.begin(), A.end()));
	cout << ans << "\n";
	return 0;
}
