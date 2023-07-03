#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	vector<int> A{
		35034, 23090, 19055, 12530, 18090
	};
	int T{};
	cin >> T;
	while (T--) {
		vector<int> B(5);
		for (int i = 0; i < 5; ++i) {
			cin >> B[i];
		}
		ll ans{};
		for (int i = 0; i < 5; ++i) {
			ans += 1LL * A[i] * B[i];
		}
		cout << "$" << ans / 100 << "." << setfill('0') << setw(2) << ans % 100 << "\n";
	}
	return 0;
}
