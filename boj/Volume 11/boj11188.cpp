#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9 + 7;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int L{}, W{}, N{}, R{};
	cin >> L >> W >> N >> R;
	R *= 2;
	vector<int> X{-L, L, 0, 0};
	vector<int> Y{0, 0, -W, W};
	vector<deque<bool>> A(N, deque<bool>(4));
	for (int i = 0; i < N; ++i) {
		int x{}, y{};
		cin >> x >> y;
		x *= 2;
		y *= 2;
		for (int j = 0; j < 4; ++j) {
			A[i][j] = (X[j] - x) * (X[j] - x) + (Y[j] - y) * (Y[j] - y) <= R * R;
		}
	}
	set<int> S;
	int ans = INF;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			for (int k = 0; k < N; ++k) {
				for (int l = 0; l < N; ++l) {
					if (A[i][0] && A[j][1] && A[k][2] && A[l][3]) {
						S.clear();
						S.insert(i);
						S.insert(j);
						S.insert(k);
						S.insert(l);
						ans = min<int>(ans, S.size());
					}
				}
			}
		}
	}
	if (ans == INF) {
		cout << "Impossible\n";
	} else {
		cout << ans << "\n";
	}
	return 0;
}
