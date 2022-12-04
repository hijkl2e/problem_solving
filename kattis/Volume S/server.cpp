#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, T{};
	cin >> N >> T;
	int ans = N;
	for (int i = 0; i < N; ++i) {
		int x{};
		cin >> x;
		if (T < x) {
			ans = i;
			break;
		} else {
			T -= x;
		}
	}
	cout << ans << "\n";
	return 0;
}
