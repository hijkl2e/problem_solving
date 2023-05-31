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
	int N{}, M{};
	cin >> N >> M;
	vector<int> A(N + 1);
	for (int i = 1; i <= N; ++i) {
		cin >> A[i];
	}
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
	FT ft(N);
	int L = 1, R = 0;
	ll ans{};
	for (auto &q : B) {
		while (q.l < L) {
			ft.update(A[--L], 1);
			ans += ft.rsq(A[L] - 1);
		}
		while (R < q.r) {
			ft.update(A[++R], 1);
			ans += ft.rsq(A[R] + 1, N);
		}
		while (L < q.l) {
			ft.update(A[L], -1);
			ans -= ft.rsq(A[L++] - 1);
		}
		while (q.r < R) {
			ft.update(A[R], -1);
			ans -= ft.rsq(A[R--] + 1, N);
		}
		C[q.idx] = ans;
	}
	for (int i = 0; i < M; ++i) {
		cout << C[i] << "\n";
	}
	return 0;
}
