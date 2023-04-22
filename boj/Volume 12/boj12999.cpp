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
		A[i] += 100000;
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
	vector<int> C(200001);
	vector<int> D(N + 1);
	vector<int> E(Q);
	int L = 1, R = 0, ans{};
	for (auto &q : B) {
		while (q.l < L) {
			int &x = C[A[--L]];
			--D[x];
			ans = max(ans, ++x);
			++D[x];
		}
		while (R < q.r) {
			int &x = C[A[++R]];
			--D[x];
			ans = max(ans, ++x);
			++D[x];
		}
		while (L < q.l) {
			int &x = C[A[L++]];
			--D[x];
			if (ans == x && D[x] == 0) {
				--ans;
			}
			++D[--x];
		}
		while (q.r < R) {
			int &x = C[A[R--]];
			--D[x];
			if (ans == x && D[x] == 0) {
				--ans;
			}
			++D[--x];
		}
		E[q.idx] = ans;
	}
	for (int i = 0; i < Q; ++i) {
		cout << E[i] << "\n";
	}
	return 0;
}
