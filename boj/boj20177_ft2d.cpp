#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using query = tuple<ll, int, int, int>;
using rec = tuple<ll, int, int>;

const ll INF = 4e18;

template <typename T = ll>
class FT2D {
public:
	FT2D(int n, int m) : ft(n + 1, vector<T>(m + 1, -INF)) { }
	T rmq(int x, int y) {
		T res = -INF;
		while (x) {
			int z = y;
			while (z) {
				res = max(res, ft[x][z]);
				z -= LSOne(z);
			}
			x -= LSOne(x);
		}
		return res;
	}
	void update(int x, int y, T v) {
		while (x < ft.size()) {
			int z = y;
			while (z < ft[x].size()) {
				ft[x][z] = max(ft[x][z], v);
				z += LSOne(z);
			}
			x += LSOne(x);
		}
	}
private:
	T LSOne(T x) {
		return x & -x;
	}
	vector<vector<T>> ft;
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, M{};
	cin >> N >> M;
	vector<ll> A(N + 1);
	for (int i = 1; i <= N; ++i) {
		cin >> A[i];
	}
	vector<ll> psum(N + 1);
	partial_sum(A.begin(), A.end(), psum.begin());
	vector<query> B(M);
	for (int i = 0; i < M; ++i) {
		auto &[u, s, e, idx] = B[i];
		cin >> s >> e >> u;
		idx = i;
	}
	sort(B.begin(), B.end());
	vector<rec> C;
	for (int i = 1; i <= N; ++i) {
		for (int j = 0; j < i; ++j) {
			C.push_back({psum[i] - psum[j], j + 1, i});
		}
	}
	sort(C.begin(), C.end());
	FT2D ft(N, N);
	vector<ll> D(M);
	for (int i = 0, j = 0; i < M; ++i) {
		auto &[u, s, e, idx] = B[i];
		while (j < C.size()) {
			auto &[val, a, b] = C[j];
			if (val <= u) {
				ft.update(N - a + 1, b, val);
			} else {
				break;
			}
			++j;
		}
		D[idx] = ft.rmq(N - s + 1, e);
	}
	for (int i = 0; i < M; ++i) {
		if (D[i] == -INF) {
			cout << "NONE\n";
		} else {
			cout << D[i] << "\n";
		}
	}
	return 0;
}
