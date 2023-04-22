#include <bits/stdc++.h>

using namespace std;

using ll = long long;

const int INF = 1e9 + 7;

struct rec {
	rec(int *_a, int _p, int _x) : a(_a), p(_p), x(_x) {
		v = *(a + p) + x;
	}
	void next() {
		v = p ? *(a + --p) + x : -INF;
	}
	int *a{}, p{}, x{}, v{};
};

bool operator<(const rec &r1, const rec &r2) {
	return r1.v < r2.v;
}

int A[4001], B[4001], C[4001], D[4001];

ll solve(priority_queue<rec> &pq) {
	ll ret{};
	int now = pq.top().v;
	while (pq.top().v == now) {
		rec r = pq.top(); pq.pop();
		r.next();
		pq.push(r);
		++ret;
	}
	return ret;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	for (int i = 0; i < N; ++i) {
		cin >> A[i] >> B[i] >> C[i] >> D[i];
		C[i] *= -1;
		D[i] *= -1;
	}
	sort(B, B + N);
	sort(D, D + N);
	priority_queue<rec> E, F;
	for (int i = 0; i < N; ++i) {
		E.push({B, N - 1, A[i]});
		F.push({D, N - 1, C[i]});
	}
	ll ans{};
	while (true) {
		int v1 = E.top().v;
		int v2 = F.top().v;
		if (v1 == -INF || v2 == -INF) {
			break;
		} else if (v1 > v2) {
			solve(E);
		} else if (v1 < v2) {
			solve(F);
		} else {
			int c1 = solve(E);
			int c2 = solve(F);
			ans += 1LL * c1 * c2;
		}
	}
	cout << ans << "\n";
	return 0;
}
