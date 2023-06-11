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
	A[0] = N;
	for (int i = 1; i <= N; ++i) {
		cin >> A[i];
	}
	partial_sum(A.begin(), A.end(), A.begin());
	int M{};
	cin >> M;
	vector<Query> B(M);
	for (int i = 0; i < M; ++i) {
		cin >> B[i].l >> B[i].r;
		--B[i].l;
		B[i].idx = i;
	}
	int sq = sqrt(N) + 1;
	sort(B.begin(), B.end(), [&](Query &q1, Query &q2) {
		return q1.l / sq < q2.l / sq || (q1.l / sq == q2.l / sq && q1.r < q2.r);
	});
	vector<int> C(2 * N + 1);
	vector<int> D(2 * N + 1);
	vector<int> E(2 * N + 1);
	vector<int> F(M);
	int L = 0, R = -1;
	int p = -1, r{}, maxv{};
	for (auto &q : B) {
		if (p < q.l / sq) {
			fill(C.begin(), C.end(), -1);
			fill(D.begin(), D.end(), -1);
			p = q.l / sq;
			r = (p + 1) * sq;
			maxv = 0;
		}
		while (r <= q.r) {
			int x = A[r];
			C[x] = C[x] == -1 ? r : C[x];
			D[x] = r++;
			maxv = max(maxv, D[x] - C[x]);
		}
		int ans = maxv;
		for (int i = min((p + 1) * sq - 1, q.r); i >= q.l; --i) {
			int x = A[i];
			if (C[x] == -1) {
				if (E[x] < i) {
					E[x] = i;
				} else {
					ans = max(ans, E[x] - i);
				}
			} else {
				ans = max(ans, D[x] - i);
			}
		}
		F[q.idx] = ans;
	}
	for (int i = 0; i < M; ++i) {
		cout << F[i] << "\n";
	}
	return 0;
}
