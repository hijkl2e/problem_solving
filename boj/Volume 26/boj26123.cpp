#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, D{};
	cin >> N >> D;
	vector<int> H(N);
	for (int i = 0; i < N; ++i) {
		cin >> H[i];
	}
	int maxv = *max_element(H.begin(), H.end());
	D = min(D, maxv);
	ll ans{};
	for (int i = 0; i < N; ++i) {
		ans += max(H[i] - maxv + D, 0);
	}
	cout << ans << "\n";
	return 0;
}
