#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, X{};
	cin >> N >> X;
	vector<int> T(N);
	for (int i = 0; i < N; ++i) {
		cin >> T[i];
	}
	int ans{};
	for (int i = 0;; i = (i + 1) % N) {
		if (T[i] < X++) {
			ans = i + 1;
			break;
		}
	}
	cout << ans << "\n";
	return 0;
}
