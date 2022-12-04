#include <bits/stdc++.h>

using namespace std;

struct Query {
	int l{}, r{}, idx{};
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, C{};
	cin >> N >> C;
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
	vector<int> ans(M);
	int L = 1, R = 0;
	vector<int> D(C + 1);
	for (auto &q : B) {
		while (q.l < L) {
			++D[A[--L]];
		}
		while (R < q.r) {
			++D[A[++R]];
		}
		while (L < q.l) {
			--D[A[L++]];
		}
		while (q.r < R) {
			--D[A[R--]];
		}
		int x = (q.r - q.l + 1) / 2;
		for (int i = 1; i <= C; ++i) {
			if (D[i] > x) {
				ans[q.idx] = i;
				break;
			}
		}
	}
	for (int x : ans) {
		if (x) {
			cout << "yes " << x << "\n";
		} else {
			cout << "no\n";
		}
	}
	return 0;
}
