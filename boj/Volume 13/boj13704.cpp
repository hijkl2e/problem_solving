#include <bits/stdc++.h>

using namespace std;

using ll = long long;

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
	for (int i = 1; i <= N; ++i) {
		A[i] ^= A[i - 1];
	}
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
	vector<int> C(1 << 20);
	vector<ll> D(M);
	int L = 0, R = -1;
	ll ans{};
	for (auto &q : B) {
		while (q.l < L) {
			ans += C[A[--L] ^ K];
			++C[A[L]];
		}
		while (R < q.r) {
			ans += C[A[++R] ^ K];
			++C[A[R]];
		}
		while (L < q.l) {
			--C[A[L]];
			ans -= C[A[L++] ^ K];
		}
		while (q.r < R) {
			--C[A[R]];
			ans -= C[A[R--] ^ K];
		}
		D[q.idx] = ans;
	}
	for (int i = 0; i < M; ++i) {
		cout << D[i] << "\n";
	}
	return 0;
}
