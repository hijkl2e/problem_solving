#include <bits/stdc++.h>

using namespace std;

struct Query {
	int l{}, r{}, idx{};
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
	vector<int> C(A.begin(), A.end());
	sort(C.begin(), C.end());
	C.resize(unique(C.begin(), C.end()) - C.begin());
	for (int i = 1; i <= N; ++i) {
		A[i] = lower_bound(C.begin(), C.end(), A[i]) - C.begin();
	}
	vector<int> D(C.size());
	vector<int> E(Q);
	int L = 1, R = 0, ans{};
	for (auto &q : B) {
		while (q.l < L) {
			int res = ++D[A[--L]];
			ans += res == 2 ? 1 : res == 3 ? -1 : 0;
		}
		while (R < q.r) {
			int res = ++D[A[++R]];
			ans += res == 2 ? 1 : res == 3 ? -1 : 0;
		}
		while (L < q.l) {
			int res = --D[A[L++]];
			ans += res == 2 ? 1 : res == 1 ? -1 : 0;
		}
		while (q.r < R) {
			int res = --D[A[R--]];
			ans += res == 2 ? 1 : res == 1 ? -1 : 0;
		}
		E[q.idx] = ans;
	}
	for (int i = 0; i < Q; ++i) {
		cout << E[i] << "\n";
	}
	return 0;
}
