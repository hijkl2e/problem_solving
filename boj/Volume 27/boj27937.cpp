#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using rec = tuple<int, int, int, int>;

struct Query {
	int l{}, r{}, idx{};
};

struct SLMO {
	void insert(int p, ll x) {
		int q = p / 451;
		for (int i = 0; i < q; ++i) {
			A[i] += x;
		}
		for (int i = 451 * q; i < p; ++i) {
			B[i] += x;
		}
	}
	ll query(int p) {
		return A[p / 451] + B[p];
	}
	ll A[451]{};
	ll B[451 * 451]{};
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, Q{};
	cin >> N >> Q;
	vector<int> A(N + 1);
	for (int i = 1; i <= N; ++i) {
		cin >> A[i];
	}
	vector<Query> B(Q);
	for (int i = 0; i < Q; ++i) {
		cin >> B[i].l >> B[i].r;
		B[i].idx = i;
	}
	int sq = sqrt(N) + 1;
	sort(B.begin(), B.end(), [&](Query &q1, Query &q2) {
		return q1.l / sq < q2.l / sq || (q1.l / sq == q2.l / sq && q1.r < q2.r);
	});
	vector<vector<rec>> C(N + 1);
	int L = 1, R = 0;
	for (int i = 0; i < Q; ++i) {
		auto &q = B[i];
		if (q.l < L) {
			C[R].push_back({q.l, L - 1, i, 1});
			L = q.l;
		}
		if (R < q.r) {
			C[L - 1].push_back({R + 1, q.r, i, -1});
			R = q.r;
		}
		if (L < q.l) {
			C[R].push_back({L, q.l - 1, i, -1});
			L = q.l;
		}
		if (q.r < R) {
			C[L - 1].push_back({q.r + 1, R, i, 1});
			R = q.r;
		}
	}
	vector<ll> D(Q);
	vector<ll> F(N + 1);
	SLMO s1, s2;
	ll sum{};
	for (int i = 0; i <= N; ++i) {
		sum += A[i];
		s1.insert(A[i], 1);
		s2.insert(A[i], A[i]);
		ll x = s1.query(A[i]);
		ll y = s2.query(A[i]);
		F[i] = (i ? F[i - 1] : 0) + (i - 2 * x) * A[i] + (2 * y - sum);
		for (auto &[a, b, c, d] : C[i]) {
			for (int j = a; j <= b; ++j) {
				x = s1.query(A[j]);
				y = s2.query(A[j]);
				D[c] += d * ((i - 2 * x) * A[j] + (2 * y - sum));
			}
		}
	}
	vector<ll> E(Q);
	L = 1, R = 0;
	for (int i = 0; i < Q; ++i) {
		auto &q = B[i];
		D[i] += (i ? D[i - 1] : 0) + (F[q.l - 1] - F[L - 1]) + (F[q.r] - F[R]);
		E[q.idx] = D[i];
		L = q.l, R = q.r;
	}
	for (ll x : E) {
		cout << x << "\n";
	}
	return 0;
}
