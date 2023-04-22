#include <bits/stdc++.h>

using namespace std;

using ll = long long;

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
	vector<ll> C(1000001);
	vector<ll> D(M);
	int L = 1, R = 0;
	ll ans{};
	for (auto &q : B) {
		while (q.l < L) {
			int &x = A[--L];
			ans += x * (2 * C[x]++ + 1);
		}
		while (R < q.r) {
			int &x = A[++R];
			ans += x * (2 * C[x]++ + 1);
		}
		while (L < q.l) {
			int &x = A[L++];
			ans -= x * (2 * C[x]-- - 1);
		}
		while (q.r < R) {
			int &x = A[R--];
			ans -= x * (2 * C[x]-- - 1);
		}
		D[q.idx] = ans;
	}
	for (int i = 0; i < M; ++i) {
		cout << D[i] << "\n";
	}
	return 0;
}
