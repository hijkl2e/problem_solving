#include <bits/stdc++.h>

using namespace std;

using ll = long long;

ll N;
vector<ll> A;

bool solve(int x) {
	if (A[x]) {
		--A[x];
		return N--;
	}
	ll cnt = 1;
	for (int i = x - 1; i > 1; --i) {
		ll minv = min(A[i], cnt);
		A[i] -= minv;
		N -= minv;
		cnt += cnt - minv;
		if (N - 2 * cnt < 0) {
			return false;
		}
	}
	N -= 2 * cnt;
	return N >= 0;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> N;
	A.resize(N + 50);
	for (int i = 0; i < N; ++i) {
		cin >> A[i];
	}
	N = accumulate(A.begin(), A.end(), 0LL);
	if (N == 1) {
		int ans = max<int>(find(A.begin(), A.end(), 1) - A.begin(), 1);
		cout << ans << "\n";
		return 0;
	}
	A[0] = A[1] = 1;
	int ans{};
	for (int i = 0; solve(i); ++i) {
		ans = i + 1;
	}
	cout << ans << "\n";
	return 0;
}
