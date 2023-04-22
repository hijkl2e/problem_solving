#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ii = pair<int, int>;

template <typename T = ll>
class Seg {
public:
	Seg(int sz) : n(sz), st(2 * sz) { }
	Seg(vector<T> &A) : n(A.size()), st(2 * A.size()) {
		copy(A.begin(), A.end(), st.begin() + n);
		for (int i = n - 1; i > 0; --i) {
			st[i] = gcd(st[2 * i], st[2 * i + 1]);
		}
	}
	T query(int l, int r) {
		T ret{};
		for (l += n, r += n; l < r; l /= 2, r /= 2) {
			if (l & 1) {
				ret = gcd(ret, st[l++]);
			}
			if (r & 1) {
				ret = gcd(st[--r], ret);
			}
		}
		return ret;
	}
private:
	int n;
	vector<T> st;
};

struct Query {
	int l{}, r{}, k{}, idx{};
};

vector<int> C(500001);
vector<int> D(715);

void solve(int p, vector<ii> &v, int e, bool f, int c) {
	for (auto &[t, g] : v) {
		if (f ? (e < t) : (t < e)) {
			C[g] += c * (abs(e - p) + 1);
			D[g / 700] += c * (abs(e - p) + 1);
			break;
		}
		C[g] += c * abs(t - p);
		D[g / 700] += c * abs(t - p);
		p = t;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	vector<int> A(N + 1);
	for (int i = 1; i <= N; ++i) {
		cin >> A[i];
	}
	Seg seg(A);
	vector<vector<ii>> L(N + 1);
	vector<vector<ii>> R(N + 1);
	for (int i = 1; i <= N; ++i) {
		int j = i;
		while (j <= N) {
			int g = seg.query(i, j + 1);
			int lo = j, hi = N + 1;
			while (lo + 1 < hi) {
				int mid = (lo + hi) / 2;
				if (seg.query(i, mid + 1) == g) {
					lo = mid;
				} else {
					hi = mid;
				}
			}
			R[i].push_back({hi, g});
			j = hi;
		}
	}
	for (int i = 1; i <= N; ++i) {
		int j = i;
		while (j) {
			int g = seg.query(j, i + 1);
			int lo = 0, hi = j;
			while (lo + 1 < hi) {
				int mid = (lo + hi) / 2;
				if (seg.query(mid, i + 1) == g) {
					hi = mid;
				} else {
					lo = mid;
				}
			}
			L[i].push_back({lo, g});
			j = lo;
		}
	}
	int Q{};
	cin >> Q;
	vector<Query> B(Q);
	for (int i = 0; i < Q; ++i) {
		cin >> B[i].l >> B[i].r >> B[i].k;
		B[i].idx = i;
	}
	int sq = sqrt(N) + 1;
	sort(B.begin(), B.end(), [&](Query &q1, Query &q2) {
		return q1.l / sq < q2.l / sq || (q1.l / sq == q2.l / sq && q1.r < q2.r);
	});
	vector<int> E(Q);
	int l = 1, r = 0;
	for (auto &q : B) {
		while (q.l < l) {
			--l;
			solve(l, R[l], r, true, 1);
		}
		while (r < q.r) {
			++r;
			solve(r, L[r], l, false, 1);
		}
		while (l < q.l) {
			solve(l, R[l], r, true, -1);
			++l;
		}
		while (q.r < r) {
			solve(r, L[r], l, false, -1);
			--r;
		}
		int p{};
		while (q.k > D[p]) {
			q.k -= D[p++];
		}
		p *= 700;
		while (q.k > C[p]) {
			q.k -= C[p++];
		}
		E[q.idx] = p;
	}
	for (int i = 0; i < Q; ++i) {
		cout << E[i] << "\n";
	}
	return 0;
}
