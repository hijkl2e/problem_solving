#include <bits/stdc++.h>

using namespace std;

using ll = long long;

const ll INF = 4e18;

template <typename T = ll>
class Seg {
public:
	Seg(int sz) : n(sz), st(2 * sz, INF) { }
	void update(int p, T val) {
		for (st[p += n] = val; p > 1; p /= 2) {
			st[p / 2] = min(st[p], st[p ^ 1]);
		}
	}
	T rmq(int l, int r) {
		T ret = INF;
		for (l += n, r += n; l < r; l /= 2, r /= 2) {
			if (l & 1) {
				ret = min(ret, st[l++]);
			}
			if (r & 1) {
				ret = min(st[--r], ret);
			}
		}
		return ret;
	}
private:
	int n;
	vector<T> st;
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	vector<vector<int>> A(3, vector<int>(N + 1));
	for (int i = 0; i < 3; ++i) {
		for (int j = 1; j <= N; ++j) {
			cin >> A[i][j];
		}
	}
	vector<vector<int>> B(2, vector<int>(N + 1));
	for (int i = 0; i < 2; ++i) {
		for (int j = 1; j <= N; ++j) {
			B[i][A[i + 1][j]] = j;
		}
	}
	Seg seg(N + 1);
	int ans{};
	for (int i = 1; i <= N; ++i) {
		if (seg.rmq(0, B[0][A[0][i]]) > B[1][A[0][i]]) {
			++ans;
		}
		seg.update(B[0][A[0][i]], B[1][A[0][i]]);
	}
	cout << ans << "\n";
	return 0;
}
