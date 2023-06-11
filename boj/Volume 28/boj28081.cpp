#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	ll R{}, C{}, K{};
	cin >> C >> R >> K;
	int N{};
	cin >> N;
	vector<ll> A(N + 1);
	for (int i = 0; i < N; ++i) {
		cin >> A[i];
	}
	int M{};
	cin >> M;
	vector<ll> B(M + 1);
	for (int i = 0; i < M; ++i) {
		cin >> B[i];
	}
	A[N++] = R, B[M++] = C;
	for (int i = N - 1; i > 0; --i) {
		A[i] -= A[i - 1];
	}
	for (int i = M - 1; i > 0; --i) {
		B[i] -= B[i - 1];
	}
	sort(B.begin(), B.end());
	ll ans{};
	for (int i = 0; i < N; ++i) {
		int lo = -1, hi = M;
		while (lo + 1 < hi) {
			int mid = (lo + hi) / 2;
			if (A[i] * B[mid] > K) {
				hi = mid;
			} else {
				lo = mid;
			}
		}
		ans += hi;
	}
	cout << ans << "\n";
	return 0;
}
