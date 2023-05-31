#include <bits/stdc++.h>

using namespace std;

using ll = long long;

template <typename T = ll>
class FT {
public:
	FT(int n) : ft(n + 1) { }
	T rsq(int i, int j) {
		return rsq(j) - rsq(i - 1);
	}
	T rsq(int j) {
		T res{};
		while (j) {
			res += ft[j];
			j -= LSOne(j);
		}
		return res;
	}
	void update(int i, T v) {
		while (i < ft.size()) {
			ft[i] += v;
			i += LSOne(i);
		}
	}
private:
	T LSOne(T x) {
		return x & -x;
	}
	vector<T> ft;
};

struct Query {
	int l{}, r{}, idx{};
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, K{};
	cin >> N >> K;
	vector<int> A(N + 1);
	for (int i = 1; i <= N; ++i) {
		cin >> A[i];
	}
	int M{};
	cin >> M;
	vector<Query> B(M);
	for (int i = 0; i < M; ++i) {
		cin >> B[i].l >> B[i].r;
		B[i].idx = i;
	}
	int sq = sqrt(N) + 1;
	sort(B.begin(), B.end(), [&](Query &q1, Query &q2) {
		return q1.l / sq < q2.l / sq || (q1.l / sq == q2.l / sq && q1.r < q2.r);
	});
	vector<ll> C(M);
	const int sz = 100001;
	FT ft(sz);
	int L = 1, R = 0;
	ll ans{};
	for (auto &q : B) {
		while (q.l < L) {
			ft.update(A[--L], 1);
			ans += ft.rsq(max(A[L] - K, 1), min(A[L] + K, sz)) - 1;
		}
		while (R < q.r) {
			ft.update(A[++R], 1);
			ans += ft.rsq(max(A[R] - K, 1), min(A[R] + K, sz)) - 1;
		}
		while (L < q.l) {
			ans -= ft.rsq(max(A[L] - K, 1), min(A[L] + K, sz)) - 1;
			ft.update(A[L++], -1);
		}
		while (q.r < R) {
			ans -= ft.rsq(max(A[R] - K, 1), min(A[R] + K, sz)) - 1;
			ft.update(A[R--], -1);
		}
		C[q.idx] = ans;
	}
	for (int i = 0; i < M; ++i) {
		cout << C[i] << "\n";
	}
	return 0;
}
