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
	vector<int> C(1000001);
	vector<int> D(M);
	int L = 1, R = 0, ans{};
	for (auto &q : B) {
		while (q.l < L) {
			if (C[A[--L]]++ == 0) {
				++ans;
			}
		}
		while (R < q.r) {
			if (C[A[++R]]++ == 0) {
				++ans;
			}
		}
		while (L < q.l) {
			if (--C[A[L++]] == 0) {
				--ans;
			}
		}
		while (q.r < R) {
			if (--C[A[R--]] == 0) {
				--ans;
			}
		}
		D[q.idx] = ans;
	}
	for (int i = 0; i < M; ++i) {
		cout << D[i] << "\n";
	}
	return 0;
}
