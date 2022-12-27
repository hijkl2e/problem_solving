#include <bits/stdc++.h>

using namespace std;

using state = tuple<int, int, int, int, int>;

bool vst[102][102][102][102];

bool chk(int t, int x, int y) {
	return t ? (x > y || y - x == 10) : (x < y || x - y == 10);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	vector<int> A(N / 2);
	vector<int> B(N / 2);
	for (int i = 0; i < N / 2; ++i) {
		cin >> A[i] >> B[i];
	}
	queue<state> q;
	vst[0][0][101][101] = true;
	q.push({0, 0, 101, 101, 0});
	vector<int> C(4);
	bool yes{};
	while (q.size()) {
		auto [a, b, c, d, e] = q.front(); q.pop();
		if (e == N / 2) {
			yes = true;
			break;
		}
		for (int i = 0; i < 2; ++i) {
			for (int j = 0; j < 4; ++j) {
				for (int k = 0; k < 4; ++k) {
					if (i && j != k) {
						continue;
					}
					C = {a, b, c, d};
					if (chk(j / 2, C[j], A[e])) {
						C[j] = A[e];
						if (chk(k / 2, C[k], B[e])) {
							C[k] = B[e];
							for (int l = 0; l < 4; l += 2) {
								if (C[l] > C[l + 1]) {
									swap(C[l], C[l + 1]);
								}
							}
							auto &v = vst[C[0]][C[1]][C[2]][C[3]];
							if (!v) {
								v = true;
								q.push({C[0], C[1], C[2], C[3], e + 1});
							}
						}
					}
				}
			}
			swap(A[e], B[e]);
		}
	}
	cout << (yes ? "WIN" : "LOSE") << "\n";
	return 0;
}
