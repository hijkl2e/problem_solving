#include <bits/stdc++.h>

using namespace std;

struct Query {
	int l{}, r{}, idx{};
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
	int sq = sqrt(N) + 1;
	sort(C.begin(), C.end(), [&](Query &q1, Query &q2) {
		return q1.l / sq < q2.l / sq || (q1.l / sq == q2.l / sq && q1.r < q2.r);
	});
	vector<int> D(B.size());
	vector<int> ans(Q);
	int L = 1, R = 0, cnt = 0;
	for (auto &q : C) {
		while (q.l < L) {
			cnt += ++D[A[--L]] == 1;
		}
		while (R < q.r) {
			cnt += ++D[A[++R]] == 1;
		}
		while (L < q.l) {
			cnt -= --D[A[L++]] == 0;
		}
		while (q.r < R) {
			cnt -= --D[A[R--]] == 0;
		}
		ans[q.idx] = cnt;
	}
	for (int x : ans) {
		cout << x << "\n";
	}
	return 0;
}
