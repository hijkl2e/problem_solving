#include <bits/stdc++.h>

using namespace std;

using ll = long long;

struct Query {
	int l{}, r{}, idx{};
};

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

template <typename T = ll>
class RUPQ {
public:
	RUPQ(int n) : ft(n + 1) { }
	void range_update(int ui, int uj, T v) {
		ft.update(ui, v);
		ft.update(uj + 1, -v);
	}
	T point_query(int i) {
		return ft.rsq(i);
	}
private:
	FT<T> ft;
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	vector<int> A(N + 1);
	for (int i = 1; i <= N; ++i) {
		cin >> A[i];
	}
	vector<int> B(A.begin(), A.end());
	sort(B.begin(), B.end());
	B.resize(unique(B.begin(), B.end()) - B.begin());
	for (int i = 1; i <= N; ++i) {
		A[i] = lower_bound(B.begin(), B.end(), A[i]) - B.begin();
	}
	int Q{};
	cin >> Q;
	vector<Query> C(Q);
	for (int i = 0; i < Q; ++i) {
		cin >> C[i].l >> C[i].r;
		C[i].idx = i;
	}
	sort(C.begin(), C.end(), [](Query &q1, Query &q2) {
		return q1.r < q2.r;
	});
	int R{};
	RUPQ ft(N);
	vector<int> D(B.size());
	vector<int> ans(Q);
	for (auto &q : C) {
		while (R < q.r) {
			++R;
			ft.range_update(D[A[R]] + 1, R, 1);
			D[A[R]] = R;
		}
		ans[q.idx] = ft.point_query(q.l);
	}
	for (int x : ans) {
		cout << x << "\n";
	}
	return 0;
}
