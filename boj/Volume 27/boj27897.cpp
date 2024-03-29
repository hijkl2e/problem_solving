#include <bits/stdc++.h>

using namespace std;

using ll = long long;

vector<int> A;

ll solve(int S, int E) {
	if (S + 1 == E) {
		return 0;
	}
	ll ret{};
	int mid = (S + E) / 2;
	ret += solve(S, mid) + solve(mid, E);
	for (int i = S, j = mid; i < mid && j < E;) {
		if (A[i] > A[j]) {
			ret += mid - i;
			++j;
		} else {
			++i;
		}
	}
	sort(A.begin() + S, A.begin() + E);
	return ret;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	ll N{}, L{};
	cin >> N >> L;
	A.resize(N);
	for (int i = 0; i < N; ++i) {
		cin >> A[i];
	}
	ll ans = min(solve(0, N) + L, N * (N - 1) / 2);
	cout << ans << "\n";
	return 0;
}
