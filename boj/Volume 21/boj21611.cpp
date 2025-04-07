#include <bits/stdc++.h>

using namespace std;

using ii = pair<int, int>;

const int dx[4]{0, 1, 0, -1};
const int dy[4]{-1, 0, 1, 0};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, M{};
	cin >> N >> M;
	vector<vector<int>> A(N, vector<int>(N));
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			cin >> A[i][j];
		}
	}
	vector<vector<int>> B(N, vector<int>(N));
	int x{}, y{}, d{}, z1{}, z2{}, p{};
	x = y = N / 2;
	B[x][y] = N * N - 1;
	while (x || y) {
		x += dx[d];
		y += dy[d];
		B[x][y] = p++;
		if (z1-- == 0) {
			z1 = ++z2 / 2;
			d = (d + 1) % 4;
		}
	}
	vector<int> C(N * N);
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			C[B[i][j]] = A[i][j];
		}
	}
	while (C.size() && C.back() == 0) {
		C.pop_back();
	}
	int ans{};
	while (M--) {
		int x{}, y{}, d{}, s{};
		cin >> d >> s;
		d = d == 1 ? 3 : d == 2 ? 1 : d == 3 ? 0 : 2;
		x = y = N / 2;
		while (s--) {
			x += dx[d];
			y += dy[d];
			if (B[x][y] < C.size()) {
				C[B[x][y]] = -1;
			}
		}
		vector<ii> D;
		for (int i = 0; i < C.size(); ++i) {
			if (C[i] == -1) {
				continue;
			}
			if (D.size() && D.back().first == C[i]) {
				++D.back().second;
			} else {
				D.push_back({C[i], 1});
			}
		}
		bool flag = true;
		while (flag) {
			flag = false;
			vector<ii> E;
			for (auto &p : D) {
				if (p.second < 4) {
					E.push_back(p);
				} else {
					ans += p.first * p.second;
					flag = true;
				}
			}
			D.clear();
			for (auto &p : E) {
				if (D.size() && D.back().first == p.first) {
					D.back().second += p.second;
				} else {
					D.push_back(p);
				}
			}
		}
		C.clear();
		for (auto &p : D) {
			C.push_back(p.second);
			C.push_back(p.first);
		}
		C.resize(min<int>(C.size(), N * N - 1));
	}
	cout << ans << "\n";
	return 0;
}
