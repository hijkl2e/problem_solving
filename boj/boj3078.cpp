#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, K{};
	cin >> N >> K;
	vector<int> A(N);
	for (int i = 0; i < N; ++i) {
		string s;
		cin >> s;
		A[i] = s.size();
	}
	vector<int> B(21);
	ll ans{};
	for (int i = 0; i < N; ++i) {
		ans += B[A[i]]++;
		if (i >= K) {
			--B[A[i - K]];
		}
	}
	cout << ans << "\n";
	return 0;
}
