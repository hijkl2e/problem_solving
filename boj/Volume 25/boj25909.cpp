#include <bits/stdc++.h>

using namespace std;

using ii = pair<int, int>;

const int INF = 1e6 + 7;
const int dx[4]{1, -1, 0, 0};
const int dy[4]{0, 0, 1, -1};

map<ii, vector<int>> when;

int solve(int X) {
	int ret{};
	for (auto &[now, V] : when) {
		int T = V[0];
		for (int i = 1; i < V.size(); ++i) {
			if (V[i] - T >= X) {
				T = V[i];
				++ret;
			}
		}
	}
	return ret;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	map<char, int> d2i{
		{'E', 0}, {'W', 1}, {'S', 2}, {'N', 3}
	};
	int N{}, K{};
	cin >> N >> K;
	vector<int> A(N);
	vector<int> B(N);
	for (int i = 0; i < N; ++i) {
		char c{};
		cin >> c >> B[i];
		A[i] = d2i[c];
	}
	ii now{};
	auto &[x, y] = now;
	for (int i = 0, t = 1; i < N; ++i) {
		for (int j = 0; j < B[i]; ++j, ++t) {
			x += dx[A[i]];
			y += dy[A[i]];
			when[now].push_back(t);
		}
	}
	int lo = 0, hi = INF;
	while (lo + 1 < hi) {
		int mid = (lo + hi) / 2;
		if (solve(mid) >= K) {
			lo = mid;
		} else {
			hi = mid;
		}
	}
	cout << (lo ? lo : -1) << "\n";
	return 0;
}
